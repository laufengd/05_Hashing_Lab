05_Hashing_Lab
==============

Implement a hash table in C++

Requirements
------------

1. `keyExists`, `find`, `remove`, and `size` should all be O(1)
2. `add` should be reasonably fast. Use linear probing to find an open slot in the hash table. This will be O(1), on average, except when `grow` is called.
3. `grow` should be O(n)
4. Do not leak memory


Reading
=======
"Open Data Structures," Chapter 5, except for 5.2.3. http://opendatastructures.org/ods-cpp/5_Hash_Tables.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. All functions pass the tests and run in O(1) time.
2. Add() passes tests and uses linear probing as described in the books
3. grow() passes tests and is in O(n) time
4. Destructors were used to prevent memory leaks

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

	I can see in some circumstances that if 'find()' returned a value of 'NULL', it would be problematic if it were incorporated in another functions.
	However, I find the 'keyExists()' function to be a little redundant because 'calcIndex()' already returns 'numItems' if a key cannot be found. For me, 
	all my keyExists function does is determine whether 'calcIndex' returns 'numItems'. The only purpose I see is for it is that it makes some of the code more understandable.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I had trouble at first because I didn't exactly know what the 'hash()' function was doing. Once I looked at it and understood what was happening to a key, I found that everything made more sense. 