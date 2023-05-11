#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
    public:
vector<int>nodes;
MaxHeap()
{

}
void up_heapify(int idx)
{
    while(idx>0 && nodes[idx] > nodes[idx-1]/2)
    {
        swap(nodes[idx],nodes[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}
void insert(int x)
{
    nodes.push_back(x);
    up_heapify(nodes.size()-1);


}

void printHeap()
{
    for(int i=0;i<nodes.size();i++)
    {
        cout<<nodes[i]<<" ";
    }
    cout<<"\n";
}
//Complexity O(logn)
void down_heapify(int idx)
{
    while(1)//
    {
        int largest = idx;
        int l = 2*idx + 1;
        int r = 2*idx + 2;
        if(nodes.size() && nodes[largest]<nodes[l])
        {
            largest = l;
        }
        if(r<nodes.size() && nodes[largest]<nodes[r])
        {
            largest = r;

        }
        if(largest == idx)

            break;
            swap(nodes[idx],nodes[largest]);
            idx = largest;

    }
}
//Complexity O(logn)
void Delete(int idx)
{
    if(idx >= nodes.size())
        return;
    swap(nodes[idx],nodes[nodes.size()-1]);
    nodes.pop_back();//last element erase kore dea.   last element delete kore O(1)
    down_heapify(idx);
}
//complexity O(1)
int getMax()
{
    if(nodes.empty())
    {
        cout<<"Heap is empty ! \n";
        return -1;
    }
    return nodes[0];//Max value to root a take tai root holo 0 tomo index er value ;
}
//complexity O(logn)
int ExtractMax()
{
    int ret = nodes[0];
    Delete(0);
    return ret;
}

};

int main()
{

   int v;
   cin>>v;
   cout<<v<<" "; 
// MaxHeap heap;
// heap.insert(4);
// heap.insert(7);
// heap.insert(9);
// heap.insert(1);
// heap.insert(10);
// heap.insert(20);
// heap.insert(30);
// cout<<"Max Element  = "<<heap.getMax()<<"\n";

// //heap.printHeap();
// cout<<"ExtactMax Element  = "<<heap.ExtractMax()<<"\n";
// cout<<"ExtactMax Element  = "<<heap.ExtractMax()<<"\n";


// return 0;
}
