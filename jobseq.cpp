#include<iostream>
#include<algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
    
};

bool comparison(Job a, Job b)
{
    return (a.profit>b.profit);
}

//function to print the sequence of jobs that maximizes profit

void printJobScheduling(Job arr[], int n){
    sort(arr, arr+n , comparison); //sort jobs in decreasing order of profit
    
    int result[n];
    bool slot[n];
    
    //initialize all slots to be free
    for(int i=0; i<n; i++ )
    {
        slot[i] = false;
    }
    
    //iterate through all given jobs
    for(int i=0; i<n; i++)
    {
        //find a free slot for this job
        for(int j= min(n, arr[i].deadline)-1; j>=0 ; j--){
            //free slot found
            if(slot[j]== false){
                result[j] = i; //add this job to result
                slot[j] = true; //make this slot occupied
                break;
            }
        }
    }
    
    //print the result
    for(int i=0; i<n; i++)
    {
        if(slot[i])
        {
            cout<<arr[result[i]].id<<" ";
        }
    }
    cout<<endl;
}


int main()
{
    int n;
    cout<<"Enter the number of jobs:"<<endl;
    cin>>n;
    
    //dynamically allocate memory for the array of jobs
    Job *arr = new Job[n];
    
     // Input job details from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, deadline, and profit for job " << i + 1 << ": ";
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }

    cout << "Following is the maximum profit sequence of jobs:\n";
    printJobScheduling(arr, n);

    // Free dynamically allocated memory
    delete[] arr;
    
    return 0;

}

