//²»¿ªlong long ¼û×æ×Ú
//2??along long ??¡Á?¡Á¨²  
#include<bits/stdc++.h>
using namespace std;
const int N=  505 ,M=5e5+10;
vector<int>a[M],t[M];
int w[M];
long long ma[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,c,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int aa,tt;
            cin>>aa>>tt;
            a[aa].push_back(i);
            t[aa].push_back(tt);
        }
    }
    memset(ma,0x3f,sizeof ma);
    for(int i=0;i<=n;i++)ma[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int s=a[i].size();
        for(int j=0;j<s;j++)
            for(int k=j+1;k<s;k++)
            {
                ma[a[i][j]][a[i][k]]=min(1ll*t[i][j]+t[i][k],ma[a[i][j]][a[i][k]]);
                ma[a[i][k]][a[i][j]]=min(1ll*t[i][j]+t[i][k],ma[a[i][k]][a[i][j]]);
            }
    }
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                ma[j][i]=min(ma[j][i],ma[j][k]+ma[k][i]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        long long dis=1e18+7;
        cin>>x>>y;
        for(int i=0;i<a[x].size();i++)
            for(int j=0;j<a[y].size();j++)
                dis=min(dis,ma[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
        cout<<dis+w[x]+w[y]<<'\n';
    }
    return 0;
}

//freopen(" ");
