#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> T;
        int left = low;
        int right = mid + 1;
        
        while(left<=mid && right<=high){
            if(arr[left] <= arr[right]){
                T.push_back(arr[left]);
                left++;
            }
            else{
                T.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            T.push_back(arr[left]);
                left++;
        }
        while(right<=high){
            T.push_back(arr[right]);
                right++;
        }
        for(int i = low; i<=high; i++){
            arr[i] = T[i - low];
        }
    }
    void mSort(vector<int> &arr, int low, int high){
        if(low == high) return;
        int mid = (low + high)/2;
        mSort(arr, low, mid);
        mSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    vector<int> mergeSort(vector<int>& nums) {
        nums = {3,1,2,4,1,5,6,2,4};
        int n = nums.size();
        mSort(nums, 0, n-1);

        return nums;
    }
};

int main() {
    Solution sorter;

    vector<int> my_array = {3,1,2,4,1,5,6,2,4}; 
    
    cout << "Original array: ";
    for (int x : my_array) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> sorted_array = sorter.mergeSort(my_array); 

    cout << "Sorted array:   ";
    for (int x : sorted_array) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}