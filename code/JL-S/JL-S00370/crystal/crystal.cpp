#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[10000000];
int maxn,t;
int main()
{
    freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(int i=0;i<10000000;i++)
    {
       if(b[i]>maxn) maxn=b[i],t=i;
    }
    if((t-1)/b[t-1]<=m&&t>=2)
     if(m-t>=0) cout<<(b[t]+b[t-1]);
    else cout<<b[t];
    return 0;
}
