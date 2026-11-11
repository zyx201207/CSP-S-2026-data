#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxi=0x7fff;
int m,n;
int a[maxi];
int check(int x)
{
    int k=a[x],c=0;
    for(int i=1;i<x;i++)
    {
        int b=k-a[i];
        c+=b;
    }
    return c;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n,v,w;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        v=check(mid);
        if(v<=m)
        {
            l=mid+1;
            w=v;
        }
        else if(v>m) r=mid-1;
    }
    if(w==m)l--;
    cout<<l;
    return 0;
}
