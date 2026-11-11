#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500010],k[510],a[510][500010],t[510][500010],ans=0;
void dfs(int g,int b,int sum)
{
    if(g==b)
    {
        cnt=sum;
        return;
    }
    if(g<0||g>m) return;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            if(a[i][j]==g)
            {
                sum+=t[i][1]+t[i][2];
                if(j=1) dfs(a[i][j+1],b,sum);
                else if(j==2) dfs(a[i][j-1],b,sum);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=p;i++){
        long long x,y;
        cin>>x>>y;
        ans+=w[x]+w[y];
        int cnt=0;
        dfs(x,y,0);
        cout<<ans+cnt<<endl;
    }
    return 0;
}
