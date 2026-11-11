#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,kk,ki,ti,x,y;
long long ans;
const int maxm=5*1e5+5;
long long INF=1e16;
int w[500005],th[500005];
vector<int> e[500005];
vector<int> ee[500005];
//点到地铁线
long long sub[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>kk;
    	for(int j=1;j<=kk;j++)
		{
			cin>>ki>>ti;
			e[ki].push_back(i);
			ee[ki].push_back(ti);
		}

	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
		    sub[i][j]=INF;
		}
		sub[i][i]=0;
	}
	for(int i=1;i<=m;i++)
    {
        for(int j=0;j<e[i].size();j++)
        {
            for(int k=0;k<j;k++)
            {
                sub[e[i][k]][e[i][j]]=sub[e[i][j]][e[i][k]]=min(sub[e[i][j]][e[i][k]],(long long)(ee[i][j]+ee[i][k]));

            }
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(int k=1;k<=n;k++)
            {
                sub[j][i]=sub[i][j]=min(sub[i][j],sub[i][k]+sub[k][j]);
            }
        }
    }
	for(int i=1;i<=q;i++)
	{
	    ans=INF;
	    cin>>x>>y;
	    for(int j=0;j<e[x].size();j++)
        {
            for(int k=0;k<e[y].size();k++)
            {
                ans=min(ans,sub[e[x][j]][e[y][k]]+ee[x][j]+ee[y][k]);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
	}
    return 0;
}

