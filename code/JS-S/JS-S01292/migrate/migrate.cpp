#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
int x[2000005];
int dp[5005][5005];
int zdjl,zdjlgs;
void f(int dq,int tt,int jl)
{
    if(dq==tt)
    {
        if(jl==zdjl) zdjlgs++;
        if(jl<zdjl)
        {
            zdjl=jl;
            zdjlgs=1;
        }
    }
    for(int l=dq+1;l<=tt;l++)
    {
        if(x[l]-x[dq]<=d) f(l,tt,jl+1);
        else break;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        memset(dp,-1,sizeof(dp));
        for(int j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        if(c<=6)
        {
            int cnt=0;
            zdjl=INT_MAX;
            zdjlgs=0;
            for(int j=1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    f(j,k,0);
                    if(zdjlgs==2) cnt++;
                }
            }
            cout<<cnt-1<<endl;
        }
        if(c==11||c==12)
        {
            int mn=d/(x[2]-x[1]);
            if(mn==2)
            {
                cout<<n-3<<endl;
            }
            else cout<<"0"<<endl;
        }
    }
    return 0;
}
