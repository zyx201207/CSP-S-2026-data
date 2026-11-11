#include<bits/stdc++.h>
using namespace std;
const int M=5e5+100,N=5e2+10;
int c,n,m,d,q,w[M],k[N],f[M+N];
vector<pair<int,int> >v[M+N];
void dij(int s,int r)
{
	for(int i=1;i<=m;i++) f[i]=2e9;
	for(int i=M+1;i<=M+n;i++) f[i]=2e9;
	f[s]=0;
	priority_queue<pair<int,int>>p;
	p.push(make_pair(0,s));
	while(!p.empty())
	{
		int g=p.top().second;
		if(g==r)
			return;
		p.pop();
		for(auto i:v[g])
		{
			int x=i.first,y=i.second;
			if(f[x]>f[g]+y)
				f[x]=f[g]+y,p.push(make_pair(-f[x],x));
		}
	}
	return ;
}
int main()
{
	//
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(make_pair(i+M,y));
			v[i+M].push_back(make_pair(x,y));
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		dij(x,y);
		cout<<f[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}