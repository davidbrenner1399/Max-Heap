#include <vector>
#include <iostream>
#include <algorithm>



using namespace std;

template <typename T>
class maxheap
{
public:

    maxheap(int capacity);          // constructor

    void insert(T val);             // insert function

    T deleteMax();                  // return and delete max value

    void printLevel();              // print in a heap-like structure

    void printArray();              // print all values on a single line

    void order(int i);              // function to help me maintain order


private:

    vector<T> heap;                 // heap will be a vector under the hood
    int size;                       // variable for how big heap actually is
    int capacity;                   // variable for the capacity of the heap

    int parentNode(int i)               // function to determine postion of parent
    {                                   // of a given node
        return (i-1) / 2;
    }

    int leftChild(int i)                 // function to determine postion left-child
    {                                    // of a given node
        return 2 * i + 1;
    }

    int rightChild(int i)                // function to determine postion right-child
    {                                    // of a given node
        return 2 * i + 2;
    }

};

template <typename T>
maxheap<T>::maxheap(int capacity)
{
    size = 0;                   // heap will have nothing in it
    this->capacity = capacity;  // set our capacity member equal to user's variable

    heap.resize(capacity);      // resize heap accordingly 

}

template <typename T>
void maxheap<T>::insert(T val)
{
    
    //increase size
    ++size;

    // make sure that we still have space
    if(size > capacity)
    {
        cout << "MAX HEAP FULL" << endl;
        return ;
    }


    //insert the new value at the end

    int i = size - 1;
    heap[i] = val;

    while(i != 0 && heap[parentNode(i)] < heap[i])  //want parent node to be larger so make sure that's true otherwise swap the two
    {
        swap(heap[i], heap[parentNode(i)]);
        i = parentNode(i);
    }
   
   
    
    
}

template <typename T>
T maxheap<T>::deleteMax()
{
    //make sure we are not empty

    if(size == 0)
    {
        cout << "empty heap" ;
        return -99;

    }
    else if( size == 1)     
    {
        size--;             // decrease size because we deleted the only thing in it
        return heap[0];
    }
    else
    {
        T root = heap[0];       // store root in temp variable called root

        heap[0] = heap[size - 1];       // replace root with newest inserted value
        size--;                         // decrease size

        order(0);                       // maintain our order 

        return root;                    // return temp variable which will be max value
    }
    

}

template <typename T>
void maxheap<T>::order(int i)
{
    //setting initial conditions

    int l = leftChild(i);            //left child
    int r = rightChild(i);           // right child
    int largest = i;

    if((l < size) && (heap[l] > heap[largest]))        // if left child is larger, make that the new largest
    {
        largest = l;
    }

    if((r < size) && (heap[r] > heap[largest]))    // same logic but for right child
    {
        largest = r;
    }

    if(largest != i)                       //swap the two
    {
        swap(heap[i], heap[largest]);
        order(largest);                    //reorder with correct largest value
    }
}

template <typename T>
void maxheap<T>::printArray()
{
    for(int i = 0; i < size; ++i)
    {
        cout << heap.at(i) << " ";
    }
}

template <typename T>
void maxheap<T>::printLevel()
{
    
    int newline_tracker = 1;
    int index = 0;

    while(index < size)     // while index != size of heap do...
    {
        for(int i = 0; i < newline_tracker && index < size ; ++i)   // while we are not equal to new line tracker
        {                                           // display value and increase index
            cout << heap[index] << " ";
            index++;
        }
        newline_tracker = newline_tracker * 2;                       // if we reached here we are not less than newline
                                                    // tracker so double new line tracker and continue running
                                                    // this will allow us to show twice as many numbers as the 
                                                    // last line
        cout << endl;
    }
  

}
