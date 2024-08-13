/*
    Given a sorted array of N elements and a integer K
    Now the array is rotated at some pivot/index unknown
    Find the index at which K is present in array

    NOTE: There are no duplicate elements in given array
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Let's consider a sorted array: {1, 2, 3, 4, 5}. 
    If we rotate this array at index 3, it will become: {4, 5, 1, 2, 3}. 
    In essence, we moved the element at the last index to the front, 
    while shifting the remaining elements to the right. We performed this process twice.
*/

// O(logN)
int Find_Element(vector<int> &v,int n,int target)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]==target)
            return mid;
        else if(v[mid]<=v[r])
        {
            if(target>=v[mid] && target<=v[r])
                l=mid+1;
            else
                r=mid-1;
        }
        else if(v[mid]>=v[l])
        {
            if(target>=v[l] && target<=v[mid])
                r=mid-1;
            else
                l=mid+1;
        }
    }
    return -1;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ind = Find_Element(v,n,target);
    cout<<"The index: "<<ind<<endl;
    return 0;
}