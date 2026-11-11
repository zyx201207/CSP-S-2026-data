#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        if(n<=3e2)
        {
            vector<int> x(n+1);
            for(int i=1;i<=n;++i) cin>>x[i];
            vector<vector<int>> gra(n+1,vector<int>(n+1,1e18));
            for(int i=1;i<=n;++i) gra[i][i]=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(abs(x[i]-x[j])>d) continue;
                    gra[i][j]=1;
                }
            } 
            for(int k=1;k<=n;++k)
            {
                for(int i=1;i<=n;++i)
                {
                    for(int j=1;j<=n;++j)
                    {
                        gra[i][j]=min(gra[i][j],gra[i][k]+gra[k][j]);
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=i;j<=n;++j)
                {
                    int cnt=0;
                    for(int k=i+1;k<j;++k) cnt+=(gra[i][k]+gra[k][j]==gra[i][j]); 
                    if(cnt==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }
        else
        {
            vector<int> x(n+1);
            for(int i=1;i<=n;++i) cin>>x[i];
            cout<<"0\n";
        }
    }
}