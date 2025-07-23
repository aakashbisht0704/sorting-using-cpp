#include <iostream>

using namespace std;

int main(){
    int arr[] = {14,9,15,12,6,8,13};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        int j = i;
        cout << arr[i] << endl;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    for(int i=0; i<n;i++){
        cout << arr[i] << endl;
    }
}