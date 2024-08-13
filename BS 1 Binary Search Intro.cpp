/*
    Array A={3,4,6,7,9,12,16,17} of size N=8 in non-decreasing order.
    Target = 6. Find the target value in array A
*/

#include<bits/stdc++.h>
using namespace std;

// O(logN)
int find_element(vector<int> &v,int n,int target)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]==target)
            return v[mid];
        else if(v[mid]>target)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;cin>>n;
    vector<int>v(n);
    for(auto& val:v)
        cin>>val;
    int target;cin>>target;
    int ans=find_element(v,n,target);
    cout<<ans<<endl;
    return 0;
}