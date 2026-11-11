#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long n,m;
long long a[N],s[N];
int check(long long t)
{
    long long x[N]= {0};
    for(long long i=0; i<t; i++)
    {
        x[s[i]]++;
    }
    for(long long i=0; i<t; i++)
    {
        if(x[i]==2)return 1;
    }
    return 0;
}
long long findd(long long z,long long t)
{
    for(long long i=0; i<t; i++)
    {
        if(s[i]==z)return i;
    }
}
long long sum(long long z)
{
    long long h=0;
    for(long long i=0; i<z; i++)
    {
        h+=s[i];
        a[i]=0;
    }
    return h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=0; i<n; i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        long long t=0,ans;
        for(long long i=0; i<=n; i++)
        {
            if(a[i]==0)continue;
            s[t]=a[i];
            t++;
            if(check(t)==1)
            {
                long long q=findd(a[i],t);
                ans=sum(q);
            }
        }
        cout<<ans<<" ";
        for(long long i=0;i<N;i++)s[i]=0;
    }
    return 0;
}
