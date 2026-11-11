#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
}t;
long long c,n,m,d,q;
long long w0[505000];
vector<node>e[505000];
long long dis[505000],b[505000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w0[i];
	for(int i=1;i<=n;i++){
		int tn;
		cin>>tn;
		for(int j=1;j<=tn;j++){
			long long v,w;
			cin>>v>>w;
			t.v=v;t.w=w;
			e[m+i].push_back(t);
			t.v=m+i;
			e[v].push_back(t);
		}
	}
	while(q--){
		int s,f;
		cin>>s>>f;
		for(int i=1;i<=n+m;i++){
			dis[i]=1e17;
			b[i]=0;
		}
		priority_queue<pair<long long,long long> >p;
		p.push(make_pair(0,s));
		dis[s]=0;
		while(!p.empty())
		{
			long long pre=p.top().second;
			p.pop();
			if(b[pre])	continue;
			b[pre]=1;
			if(pre==f)	break;
			for(auto v:e[pre])
			{
				if(dis[pre]+v.w<dis[v.v]){
					dis[v.v]=dis[pre]+v.w;
					p.push(make_pair(-dis[v.v],v.v));
				}
			}
		}
		cout<<dis[f]+w0[s]+w0[f]<<"\n";
	}
	return 0;
}
