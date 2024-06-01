#include<bits/stdc++.h>
#include<vector>
using namespace std;


void selectionSort(vector<int> & arr, int n) {
    for (int i=0;i<arr.size(); i++)
    {
        int minIndex = i;
        for(int j=i+1; j<arr.size();j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
            
        }
        swap(arr[minIndex],arr[i]);
    }
    
}


int main()
{

    /*cout<<"enter array size"<<endl;
    int n;
    cin>>n;
    
    
     vector<int> arr(n) ;
     
     cout<<"enter "<<n<<" array elements "<<endl;
     for(int i=0; i<n; i++)
     {
         cin>>arr[i];
     }
     */

     vector<int> arr = {64, 32, 21, 11, 12};
     int n = arr.size();
     
     
    selectionSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

























