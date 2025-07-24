#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int logicFunc(vector<int> &arr, int low, int high){
        int piv = arr[low];
        int i = low;
        int j = high;

        while(i<j){
            while(arr[i] <= piv && i<high) i++;

            while(arr[j] >= piv && j>low) j--;

            if(i<j){
                //swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp; 

        return j;
    }

    void QS(vector<int> &arr, int low, int high){
        if(low < high){
            int pidx = logicFunc(arr, low, high);

            QS(arr, low, pidx-1);
            QS(arr, pidx+1, high);
        }
    }

    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();
        QS(nums, 0, n-1);

        return nums;
    }
};


int main() {
    Solution sorter;

    vector<int> my_array = {4,6,2,5,7,9,1,3}; 
    
    cout << "Original array: ";
    for (int x : my_array) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> sorted_array = sorter.quickSort(my_array); 

    cout << "Sorted array:   ";
    for (int x : sorted_array) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}