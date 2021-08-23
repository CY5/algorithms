//entire below implementation based on Errichto explanation - https://www.youtube.com/watch?v=GU7DpgHINWQ

#include <iostream>
#include <vector>

using namespace std;

void log(const string& txt,char sep='\n')
{
    std::cout << txt << sep;
}

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

template<typename T>
int lowerBoundBinarySearch(const vector<T>& arr, int Target)
{
    int left = 0;
    int right = static_cast<int>(arr.size())-1;
    int ans = -1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if (arr[mid]>=Target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    };
    return ans;
}


int main()
{
    vector<int> arr = {2,3,5,6,8,10,12};
    int nTarget1 = 10;
    int nTarget2 = 4;
    log(string("binary search index for target :" + std::to_string(nTarget1) 
                + " = " + std::to_string(binarySearch(arr, nTarget1))));
    log(string("binary search index for target :" + std::to_string(nTarget2) 
                + " = " + std::to_string(binarySearch(arr, nTarget2))));

    log(string("lower bound binary search index for target :" + std::to_string(nTarget1) 
                + " = " + std::to_string(lowerBoundBinarySearch(arr, nTarget1))));
    log(string("lower bound binary search index for target :" + std::to_string(nTarget2) 
                + " = " + std::to_string(lowerBoundBinarySearch(arr, nTarget2))));
    return 0;
}