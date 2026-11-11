#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,T,w[500005],ans[500005];
vector<int> t[500005];
int bfs(int s,int e)
{
	memset(ans,0x3f,sizeof(ans));
	ans[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		if(x==e) return ans[e]*2*T+w[s]+w[e];
		for(auto y:t[x])
		{
			ans[y]=min(ans[y],ans[x]+1);
			q.push(y);
		}
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k; k*=2;
		for(int i=1;i<=k;i++) 
		{
			int a,ti;
			cin>>a>>ti; 
			if(T==0) T=ti;
			t[a].push_back(i);
			t[i].push_back(a);
		}
	} 
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		cout<<bfs(s,e)<<endl;
	}
	return 0;
}

