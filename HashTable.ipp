//You will need this so you can make a string to throw in
//remove

#include <string>


/*

Implementing hash lab by using double hashing.

*/


template <class Key, class T>
HashTable<Key,T>::HashTable()
{

  //Initializing the size of backingArray.
  backingArraySize = hashPrimes[0];

  backingArray = new HashRecord[backingArraySize];

  numItems = 0;

  numRemoved = 0;


}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {

    //deallocate the memory
    delete[]backingArray;

    //Avoid dangling pointers.
    backingArray = NULL;

}




template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x)
{

     if( numItems + numRemoved >= backingArraySize/2 )
     {
        grow();
     }

     unsigned long index = hash(k) % backingArraySize;
     while(backingArray[index].isNull == false && backingArray[index].k != k)
     {
            //Hash again if you find a already existent element.
            index = (index + (1 + index % (backingArraySize-1))) % backingArraySize;
     }

          //Set variables.
          backingArray[index].x = x;
          backingArray[index].k = k;
          backingArray[index].isNull = false;
          numItems++;

     }



 //If the slot used to have something in it, but doesn't now, set
 //isDel to true, and isNull to false. isNull is only for slots
 //that have never been used

template <class Key, class T>
void HashTable<Key,T>::remove(Key k)
{

    if(keyExists(k) == false) {/*Do nothing*/}

    else
    {
       unsigned long index = hash(k) % backingArraySize;
       backingArray[index].isNull = false;
       backingArray[index].isDel = true;
       numItems--;
       numRemoved++;
    }
  }



template <class Key, class T>
T HashTable<Key,T>::find(Key k)
{

    if(keyExists(k)==false)
    {
        throw std::string("No such an element.");
    }
    else
    {

        unsigned long index = hash(k)% backingArraySize;

        while( (backingArray[index].isNull == false) || (backingArray[index].isDel == false))
            {
                if(backingArray[index].k == k)
                {
                        return backingArray[index].x;
                }
               index = (index + (1 + index % (backingArraySize-1))) % backingArraySize;
        }
    }
}



template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k)
{

      unsigned long index = hash(k) % backingArraySize;


      while(backingArray[index].isNull == false)
      {

        if(backingArray[index].k == k && backingArray[index].isDel == false)
          {
                return true;
          }

            index = (index + (1 + index % (backingArraySize-1))) % backingArraySize;

     }
          return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size()
{

   return numItems;

}

template <class Key, class T>
void HashTable<Key,T>::grow()
{

   int oldSize = backingArraySize;
   int newSize = 0;

   for(int i = 0;i<oldSize;i++)
   {

      if(oldSize == hashPrimes[i])
          {
              //jump to next prime.
              newSize = hashPrimes[i+1];
          }
   }

   HashRecord* temp = backingArray;
   backingArraySize = newSize;
   backingArray = new HashRecord[backingArraySize];

   //Re-calculating.
   numItems = 0;
   numRemoved = 0;

   for(int k = 0;k<oldSize;k++){
      if( (temp[k].isNull) == false && (temp[k].isDel == false) )

                 {
                     add(temp[k].k,temp[k].x);

                 }
            }
                delete [] temp;
                temp = NULL;
}





