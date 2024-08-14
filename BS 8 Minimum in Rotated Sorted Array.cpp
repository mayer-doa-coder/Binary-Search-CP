/*
    Given an array of size N having unique elements
    Sorted in ascending order and rotated between 1 and N times
    Find the minimum number in the array
*/

#include<bits/stdc++.h>
using namespace std;

// O(logN)
int Find_Minimum(vector<int> &nums,int n)
{
    int l=0,r=n-1;
    int ans=INT_MAX;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(nums[mid]<=nums[r])
        {
            ans=min(ans,nums[mid]);
            r=mid-1;
        }
        else if(nums[l]<=nums[mid])
        {
            ans=min(ans,nums[l]);
            l=mid+1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    int mini=Find_Minimum(v,n);
    cout<<mini<<endl;
    return 0;
}