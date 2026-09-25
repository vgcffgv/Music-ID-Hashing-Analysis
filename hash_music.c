#include <stdio.h>

#define SIZE 10
#define N 8

int hashTable[SIZE];

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        printf("Collision at index %d for %d\n", index, key);
        index = (index + 1) % SIZE;

        if (index == start)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

int hashSearch(int key, int *operations)
{
    int index = hashFunction(key);
    int start = index;

    *operations = 0;

    while (hashTable[index] != -1)
    {
        (*operations)++;

        if (hashTable[index] == key)
            return index;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return -1;
}

int linearSearch(int arr[], int n, int key, int *comparisons)
{
    int i;

    *comparisons = 0;

    for (i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int songs[N] = {105, 210, 315, 420, 525, 630, 735, 840};

    int i;
    int hashOps, linearOps;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("HASH TABLE INSERTION\n");
    printf("--------------------\n");

    for (i = 0; i < N; i++)
    {
        insert(songs[i]);
    }

    printf("\nFINAL HASH TABLE\n");
    printf("----------------\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }

    printf("\nSEARCH COMPARISON\n");
    printf("-----------------\n");
    printf("ID\tHashing\tLinear Search\n");

    for (i = 0; i < N; i++)
    {
        hashSearch(songs[i], &hashOps);
        linearSearch(songs, N, songs[i], &linearOps);

        printf("%d\t%d\t%d\n",
               songs[i], hashOps, linearOps);
    }

    return 0;
}
