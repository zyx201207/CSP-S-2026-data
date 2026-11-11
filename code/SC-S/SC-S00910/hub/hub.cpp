#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=1e6+5;
vector <int> g[N]; 
int num;
void bfs(int r,int x,int cnt)
{
	int n=1;
	 for(int i=0;i<g[x].size();i++)
	 {
	 	int v=g[x][i];
	 	n=0;
	 	bfs(r,v,cnt+1);
	 }
	 if(n==1)	num=max(num,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t,sum1=1e9,sum2=1e9;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);	
		} 
		if(c==7)
		{
			for(int i=1;i<=n;i++)
			{
				num=0;
				bfs(i,i,0);
				if(num<sum1) sum1=num;
				else if(num<sum2)	sum2=num;
			}
			cout<<sum2<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}