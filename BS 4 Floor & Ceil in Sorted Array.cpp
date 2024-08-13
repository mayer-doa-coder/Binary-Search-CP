#include<bits/stdc++.h>
using namespace std;

/*
    The floor of x is the largest element in the array 
    which is smaller than or equal to x( i.e. largest element in the array <= x).
*/

// O(logN)
int Floor_Value(int n,vector<int>&v,int target)
{
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]<=target)
        {
            ans=v[mid];
            l=mid+1;
        }   
        else
            r=mid-1;
    }
    return ans;
}

/*
    The ceiling of x is the smallest element in the array 
    greater than or equal to x( i.e. smallest element in the array >= x).
*/

// O(logN)
int Ceil_Value(int n,vector<int>&v,int target)
{
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]>=target)
        {
            ans=v[mid];
            r=mid-1;
        }   
        else
            l=mid+1;
    }
    return ans;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(auto &i: v)
        cin>>i;
    cout<<Floor_Value(n,v,target)<<endl;
    cout<<Ceil_Value(n,v,target)<<endl;
}