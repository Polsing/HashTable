#if !defined(_HASHTABLE_H)
#define _HASHTABLE_H
#define HASH_SIZE 5
#define REHASH_THRESHOLD 80.0f
#define REHASH_EAPAND 2.0f


#include "../Arraylist/Arraylist.h"

class HashTable
{
    private:
        Arraylist *table;
        int maxSize , curSize;

    public:
        HashTable(int maxSize = HASH_SIZE);
        ~HashTable();


        void display();
        void addkey(int key);
        int searchkey();

    private:
        int hasFunction(int key , int i);
        void rehashing();


    

};

#endif // _HASHTABLE_H
