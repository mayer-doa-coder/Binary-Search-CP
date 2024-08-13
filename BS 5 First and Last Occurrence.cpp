/*
    Given a sorted array of N elements and an integer X
    Find the first and last occurrence of X in array
*/

/*
    Given a sorted array containing N integers and a number X
    Count the occurrences of X in the given array.
    Solution:   
    Same as finding first and last occurrence of a number in array
    cout<< last-first+1 <<endl;
*/

#include<bits/stdc++.h>
using namespace std;

int First_Occurrence(vector<int> &v,int n,int target)
{
    int l=0,r=n-1;
    int ansfirst=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]==target)
        {
            ansfirst=mid;
            r=mid-1;
        }
        else if(v[mid]<target)
            l=mid+1;
        else
            r=mid-1;
    }
    return ansfirst;
}

int Last_Occurrence(vector<int> &v,int n,int target)
{
    int l=0,r=n-1;
    int anslast=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]==target)
        {
            anslast=mid;
            l=mid+1;
        }
        else if(v[mid]<target)
            l=mid+1;
        else
            r=mid-1;
    }
    return anslast;
}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(auto &i: v)
        cin>>i;

    int first=First_Occurrence(v,n,target);
    int last=Last_Occurrence(v,n,target);

    cout<<"First & Last Occurrence at index: "<<first<<" "<<last<<endl;

    return 0;
}