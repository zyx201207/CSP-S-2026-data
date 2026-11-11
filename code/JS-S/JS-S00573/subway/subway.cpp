#include<bits/stdc++.h>
using namespace std;
long long a[500005],g[500005],f[506][1005],s[1005][1005];
long long b,cod;
bool two=1;
int dfs(int t2,int t3)
{

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,st,ed,tot=1ll;
    while(cin>>c)
    {
        cin>>m>>n>>d>>q;
        for(int i=1;i<=m;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {

            cin>>b;
            if(b>2) two=0;
            for(int j=1;j<=b;j++)
            {
                cin>>f[i][j]>>g[i];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>st>>ed;
            if(two==1)
            {
                long long t1=a[st]+a[ed];
                for(int i=1;i<=b;i++)
                {
                    s[f[i][1]][f[i][2]]=g[f[i][2]];
                    s[f[i][2]][f[i][1]]=g[f[i][1]];
                }
                tot=min(tot,t1);
                cout<<tot<<endl;
            }
            else
            {
                cout<<1;
            }
        }
    }
}
