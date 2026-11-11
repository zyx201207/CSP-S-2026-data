#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5,inf=LLONG_MAX/3;
int c,n,m,d,q,l[N],a[M],t[M],d[N];
ll w[N],ans,mn=inf;
struct edge{int v,w;};
vector<edge>g[N];
priority_queue<<pair<int,int>,vector<pair<int,int>>,greater<>>q;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			cin>>a[j]>>t[j];
		}
		mn=min(mn,t[1]+t[2]);
		if(7<=c&&c<=11){
			g[a[1]].push_back({a[2],t[1]+t[2]});
			g[a[2]].push_back({a[1],t[1]+t[2]});
		}
	}
	while(q--){
		cin>>x>>y;
		if(n==2){
			cout<<w[x]+w[y]+mn<<'\n';
			continue;
		}
		if(7<=c&&c<=11){
			for(int i=1;i<=n;i++)d[i]=inf;
			d[x]=0;
			q.push({0,x});
			while(!q.empty()){
				int nw=q.top().second,w=q.top().first;
				q.pop();
				if(w>d[nw])continue;
				for(auto i:g[nw]){
					if(d[nw]+i.w<d[i.v]){
						d[i.v]=d[nw]+i.w;
						q.push({d[i.v],i.v});
					}
				}
			}
			cout<<d[y]<<'\n';
			continue;
		}
	}
	return 0;
}
