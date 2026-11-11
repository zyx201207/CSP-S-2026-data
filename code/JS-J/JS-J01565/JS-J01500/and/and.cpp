#include <bits/stdc++.h>
using namespace std;
#define int long long
int n=0,m=0,maxi=-1,a=0,maxn=-1,flag=0;
int s[200005]={0};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]>maxi) maxi=s[i];
    }
    if(m==1) cout<<maxi;
    else if(m==n)
    {
        a=s[1];
        for(int i=2;i<=n;i++) a=a&s[i];
        cout<<a;
    }
    else if(m==n-1)
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=1) a=s[1];
            else a=s[2];
            for(int j=1;j<=n;j++) if(j!=i) a=a&s[i];
            maxn=max(maxn,a);
        }
        cout<<maxn;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++) maxn=max(maxn,s[i]&s[j]);
        }
        cout<<maxn;
    }
    else
    {
        sort(s+1,s+1+n);
        a=s[n-m+1];
        for(int i=n-m+2;i<=n;i++) a=a&s[i];
        cout<<a;
    }
    return 0;
}
