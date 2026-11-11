#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int n,m,v[N],cnt,s[N],k;
int cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)
    {
        if(v[i+1]==v[i])s[++k]=i+1;
    }
    int o=s[k];
    sort(s+1,s+k+1,cmp);
    if(s[1]==0)
    {
        if(n%2==0)
            for(int i=1;i<=m;i++)
                cout<<n/2<<" ";
        else
            for(int i=1;i<=m;i++)
                cout<<n/2+1<<" ";
    }
    else
    {
        for(int i=1;i<=o;i++)
            cout<<"0"<<" ";
        if(n%2==0)
            for(int i=o;i<=m;i++)
                cout<<n/2<<" ";
        else
            for(int i=o;i<=m;i++)
                cout<<n/2+1<<" ";
    }
    return 0;
}
