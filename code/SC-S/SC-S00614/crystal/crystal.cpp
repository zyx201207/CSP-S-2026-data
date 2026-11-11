#include<bits/stdc++.h>
#define int long long 
using namespace std;

int n,m,a[500001],s[500001];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<r)
    {
        int mid=r-(r-l>>1),flag=0;
        for(int i=mid;i<=n;i++)
            flag|=((a[i]*mid-s[i]+s[i-mid])<=m);
        if(flag)
            l=mid;
        else
            r=mid-1;
    }
    cout<<l<<"\n";
}