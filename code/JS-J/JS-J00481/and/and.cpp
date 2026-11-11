#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,ab[2001];
    int maxx=-1;
    int andd;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ab[i];
    }
    for(int j=1;j<=n-1;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int s=ab[i],k;
            for(int d=2;d<=n;d++)
                k=ab[i]&ab[d];
            if(k>maxx) maxx=k;
            k=-1001;
        }
    }
    cout<<maxx;
    return 0;
}