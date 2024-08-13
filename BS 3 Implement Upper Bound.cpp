#include<bits/stdc++.h>
using namespace std;

/*
    The upper bound algorithm finds the first or the smallest index in a sorted array 
    where the value at that index is greater than the given key i.e. x.
    The upper bound is the smallest index, ind, where arr[ind] > x.
    But if any such index is not found, the upper bound algorithm returns n 
    i.e. size of the given array. The main difference between the lower and upper bound is in the condition. 
    For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.
*/

// O(logN)
int Upper_Bound(int n,vector<int> &v,int target)
{
    int l=0,r=n-1;
    int ans=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]>target)
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}

// STL
int Upper_Bound(int n,vector<int> &v, int target)
{
    int high= upper_bound(v.begin(),v.end(),target)-v.begin();
    return high;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(auto &i: v)
        cin>>i;
    cout<<Upper_Bound(n,v,target)<<endl;
}