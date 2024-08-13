#include<bits/stdc++.h>
using namespace std;

/*
    The lower bound algorithm finds the first or the smallest index in a sorted array 
    where the value at that index is greater than or equal to a given key i.e. x.
    The lower bound is the smallest index, ind, where arr[ind] >= x. 
    But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
*/

// O(logN)
int Lower_Bound(int n,vector<int> &v,int target)
{
    int l=0,r=n-1;
    int ans=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]>=target)
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
int Lower_Bound(int n,vector<int> &v, int target)
{
    int low= lower_bound(v.begin(),v.end(),target)-v.begin();
    return low;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(auto &i: v)
        cin>>i;
    cout<<Lower_Bound(n,v,target)<<endl;
}
