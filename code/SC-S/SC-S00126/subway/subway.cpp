#include<bits/stdc++.h>
using namespace std;
const int N=5010,D=31,M=2e4+10;
int m,n,t[M],c,d,q,idx,pre[2*D*M],ans[1010][1010],k,cntss[1010][1010];
class node
{
public:
	int from,to,len,ne;
	void add(int u,int v,int leng)
	{
		from=u;
		to=v;
		len=leng;
		ne=pre[u];
		pre[u]=k;
	}
}bi[2*D*M];
int solve(int s,int t)
{
	bool f[idx+10];
	for(int i=1;i<=idx;i++)
	{
		f[i]=1;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	while(!q.empty())
	{
		int fir=q.top().first,sec=q.top().second;
		q.pop();
		if(!f[sec]) continue;
		cntss[s][sec]=fir;
		f[sec]=0;
		for(int i=pre[sec];i;i=bi[i].ne)
		{
			q.push({fir+bi[i].len,bi[i].to});
		}
	}
	return -1;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	idx=m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			int a,b;
			cin>>a>>b;
			if(j==1)
			{
				bi[++k].add(a,++idx,b);
				bi[++k].add(idx,a,b);
				continue;
			}
			bi[++k].add(a,++idx,b);
			bi[++k].add(idx,a,b);
			bi[++k].add(idx-1,idx,0);
			bi[++k].add(idx,idx-1,0);
		}
	}
	for(int i=1;i<=m;i++)
	{
		solve(i,m);
	}
	for(int i=1;i<=q;i++)
	{
		int s,l;
		cin>>s>>l;
		cout<<cntss[s][l]+t[s]+t[l]<<endl;
	}
	return 0;
}