#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int binarySearch(const vector<T>& arr, T target)
{
    int left = 0; 
    int right = static_cast<int>(arr.size())-1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if (arr[mid]==target) 
            return mid;
        if (arr[left]<target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {2,3,5,6,8,10,12};
    int nTarget1 = 10;
    int nTarget2 = 9;
    cout << "Binary Search for Target :"<< nTarget1 <<" = "<< binarySearch(arr, nTarget1) << "\n";
    cout << "Binary Search for Target :"<< nTarget2 <<" = "<< binarySearch(arr, nTarget2) << "\n";
    return 0;
}