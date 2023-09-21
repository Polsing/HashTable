#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int maxSize)
{
    this->maxSize = maxSize;
    curSize = 0;
    table = new Arraylist(this->maxSize);

        for(int i = 0; i< this->maxSize ; i++)
        {
            table->add(i,-1);
        }
}

HashTable::~HashTable()
{
    delete table;
}

void HashTable::display()
{
    cout<<"Hash Table"<<endl;
    for(int i = 0 ; i < maxSize ; i++)
    {
        cout<<"["<< i <<"] : ";
            if(table->get(i) < 0)
               cout<<" - "<<endl;
            else 
              printf("%2d\n" , table->get(i));
    }
    cout<<"Using: "<< curSize << "/" << maxSize <<endl;
    float percent = (float)curSize / (float)maxSize*100;
    printf("Threshold: %0.2f\n",percent);

}

void HashTable::addkey(int key)
{
    for(int i = 0 ; i < maxSize ; i++)
    {
        int index = hasFunction(key , i);
            if(table->get(index) < 0)
            {
                table->set(index , key);
                curSize++;
                break;
            }
        cout<<"key(" << key <<") => Index: "<< index <<"Collision!!!"<<endl; 
        float percent = (float)curSize / (float)maxSize *100;
        if(percent >= REHASH_THRESHOLD)
        { rehashing();}
    }
}

int HashTable::hasFunction(int key, int i)
{return ((key % maxSize) + i) % maxSize;}

void HashTable::rehashing()
{
    int oldmaxSize = maxSize;
    curSize = 0;
    maxSize = (float)maxSize * REHASH_EAPAND;
    Arraylist *newTable = new Arraylist(maxSize);
        for(int i = 0 ; i < maxSize ; i++)
        { newTable->add(i ,-1);}
    for(int i = 0 ; i < oldmaxSize ; i++)
    {
        if(table->get(i) >= 0)
        {
         for(int j = 0 ; j < maxSize ; j++)
         {
            int newindex = hasFunction(table->get(i) , j);
            if(table->get(newindex) < 0)
            {
                newTable->set(newindex , table->get(i));
                curSize++;
                break;
            }
           cout<<"Collision!!!"<<endl; 

         }
        }
   }
   delete table;
   table = newTable;
}
