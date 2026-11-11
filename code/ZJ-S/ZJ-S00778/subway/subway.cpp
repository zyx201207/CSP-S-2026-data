#include<bits/stdc++.h>
using namespace std;
const int op=5e5+5;long long t;
int w[op];//从地铁口走到站厅的时间数组 
bool stations[22][op];
int time[op][22],ways[op][505],way[op];
long long ans;
void dfs(int x,int y,int howmany)
{
	if(x==y)ans=min(ans,howmany);
	else
	{
		dfs()
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;way[i]=k;long long m=0;
		for(int j=1;j<=k;i++)
		{
			cin>>ways[i][j];
			cin>>time[i][ways[i][j]];t=time[i][ways[i][j]];
			stations[m++][ways[i][j]]=1;
		}
	}
	while(q--)
	{
		int x,y;cin>>x>>y;
		ans=2e9;
		dfs(x,y,0);
		cout<<(ans*t)<<"\n";
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
