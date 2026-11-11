#include<bits/stdc++.h>
using namespace std;
//check int
//check vis1 & vis2
//check endl
long long c,m,n,d,q,w[500010],k[510],G[360][360],im[500],StDis[500010][2],pass;
bool vis[500],vis2[500010][2];
void solve1()//for num, remember to +-1
{
	for(int I=0;I<354;I++)
	{
		for(int J=0;J<354;J++)
			if(I!=J) G[I][J]=300000000000;
	}
	long long i=n;
	for(int I=0;I<n;I++)
	{
		cin>>k[I];
		for(int J=0;J<k[I];J++)
		{
			long long x,y;
			cin>>x>>y;
			x--;
			if(!vis[x])
			{
				vis[x]=true;
				im[x]=i;
				i++;
			}
			G[I][im[x]]=y,G[im[x]][I]=y;
		}
	}
	
	
	for(int K=0;K<i;K++)
	{
		for(int I=0;I<i;I++)
		{
			for(int J=0;J<i;J++)
			{
				if(I==J) continue;
				if(G[I][J]>G[I][K]+G[K][J]) G[I][J]=G[I][K]+G[K][J];
			}
		}
	}
	
	
	for(int I=0;I<q;I++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		cout<<w[x]+w[y]+G[im[x]][im[y]]<<'\n';
	}
	return;
}
void solve2()
{
	for(int I=0;I<n;I++)
	{
		cin>>k[I];
		for(int J=0;J<k[I];J++)
		{
			int x,y;
			cin>>x>>y;
			x--;
			vis2[x][I]=true;
			StDis[x][I]=y;
		}
	}
	if(n==1)
	{
		for(int I=0;I<q;I++)
		{
			int x,y;
			cin>>x>>y;
			x--,y--;
			cout<<w[x]+w[y]+StDis[x][0]+StDis[y][0]<<endl;
		}
	}
	else
	{
		pass=LONG_LONG_MAX;
		for(int I=0;I<m;I++)
		{
			if(vis2[I][0] && vis2[I][1])
			{
				pass=min(pass,StDis[I][0]+StDis[I][1]);
			}
		}
		
		for(int I=0;I<q;I++)
		{
			int x,y;
			cin>>x>>y;
			x--,y--;
			long long ans=LONG_LONG_MAX;
			for(int I=0;I<n;I++)
			{
				if(vis2[x][I] && vis2[y][I])
				{
					ans=min(ans,StDis[x][I]+StDis[y][I]);
				}
			}
			if(vis2[x][0] && vis2[y][1])
			{
				ans=min(ans,StDis[x][0]+StDis[y][1]+pass);
			}
			if(vis2[x][1] && vis2[y][0])
			{
				ans=min(ans,StDis[x][1]+StDis[y][0]+pass);
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int I=0;I<m;I++) cin>>w[I];
	if(n<=2)
	{
		solve2();
	}
	else
	{
		solve1();
	}
	
	return 0;
}
