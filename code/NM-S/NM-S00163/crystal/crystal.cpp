#include <bits/stdc++.h>
#include<cstdio>
#define int long long
using namespace std;
int n,m;
int a[500001];
int b[500001];
int d[500001];
int t=1,w=1,an;
int ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        b[i]=a[n]-a[i];
    while(w<n)
    {
        an+=b[w];
        if(an-b[w+1]*(w-t+1)<=m)
            ans=max(ans,w-t+2);
        else
        {
            while(an-b[w+1]*(w-t+1)>m)
            {
                an-=b[t];
                t++;
            }
        }
        w++;
    }
    cout<<ans;
    return 0;
}
