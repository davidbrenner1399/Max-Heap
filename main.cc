#include "maxheap.h"
#include <ctime>


int main()
{
    srand(unsigned(time(NULL)));
    int n = 15;
    maxheap<int> heap(n);

    for(int i = 0; i < n; ++i)
    {
        heap.insert(rand() % 500 + 1);
        
    }

     heap.printLevel();

    cout << endl << endl;

    heap.deleteMax();

    heap.insert(1);

    cout << endl;

    cout << endl;

    heap.printLevel();

    cout << endl;

    heap.printArray();
    


    return 0;
}