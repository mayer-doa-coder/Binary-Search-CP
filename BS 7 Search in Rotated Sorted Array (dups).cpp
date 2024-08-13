/*
    Given a sorted array of N elements and a integer K
    Now the array is rotated at some pivot/index unknown
    Find if the integer is present in the array

    NOTE: There are duplicate elements in given array
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Handle the edge case arr[low] = arr[mid] = arr[high]:
    We simply remove arr[low] and arr[high] from our search space, without affecting the original algorithm. 
    To eliminate elements arr[low] and arr[high], 
    we can achieve this by simply incrementing the low pointer and decrementing the high pointer 
    by one step. We will continue until the condition arr[low] = arr[mid] = arr[high] is no longer satisfied.
*/

// O(logN) for the best and average case. O(N/2) for the worst case.
bool Occurrence(vector<int> &v,int n,int target)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]==target)
            return true;
        if(v[mid]==v[l] && v[mid]==v[r])
        {
            l=l+1;
            r=r-1;
            continue;
        }
        if(v[mid]>=v[l])
        {
            if(v[l]<=target && v[mid]>=target)
                r=mid-1;
            else
                l=mid+1;
        }
        else if(v[mid]<=v[r])
        {
            if(v[mid]<=target && v[r]>=target)
                l=mid+1;
            else
                r=mid-1;
        }
    }
    return false;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    bool found=Occurrence(v,n,target);
    cout<<found<<endl;
    return 0;
}