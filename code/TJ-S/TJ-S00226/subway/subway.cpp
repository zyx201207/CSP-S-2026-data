#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const int N=5e5+5;
int c,n,m,d,q;
vector<pll> a[N];
ll w[N],dis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m+n;i++){
		dis[i]=1e18;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int b;
			ll t;
			cin>>b>>t;
			
			a[b].push_back({t,i+m});
			a[i+m].push_back({t,b});
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		int sum=w[s]+w[e];

		priority_queue<pll,vector<pll>,greater<pll> >pq;
		dis[s]=0;
		pq.push({0,s});
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();
			for(int i=0;i<a[u].size();i++){
				ll v=a[u][i].second,w=a[u][i].first;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					pq.push({dis[v],v});
				}
			}
		}
		cout<<dis[e]+sum<<endl;
		for(int i=1;i<=m+n;i++){
			dis[i]=1e18;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
