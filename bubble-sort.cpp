#include <iostream>

using namespace std;

int main(){
    int arr[] = {13,24,46,20,9,52};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=n-1; i>=1;i--){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                //swap
                int temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for(int i=0; i<n;i++){
        cout << arr[i] << endl;
    }
}