/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,k,kk,t,cnt,w[500005],pt,dist[2000005];
bool vis[2000006];
vector<pair<ll,ll> > a[2000006];
void dij(ll s,ll t){
	priority_queue<pair<ll,ll> > pq;
	for(int i=1;i<=cnt;i++){
		dist[i]=(ll)9e18;
		vis[i]=0;
	}
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		pair<ll,ll> p=pq.top();
		pq.pop();
		ll w=p.first;
		ll v=p.second;
//		cout<<v<<" "<<w<<"\n";
		if(vis[v]) continue;
		vis[v]=1;
		for(auto i:a[v]){
			if(dist[v]+i.second<dist[i.first]){
				dist[i.first]=dist[v]+i.second;
				pq.push({dist[i.first],i.first});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>kk>>t;
		pt=++cnt;
		a[pt].push_back({kk,t});
		a[kk].push_back({pt,t});
//		cout<<"        "<<kk<<" "<<pt<<"\n";
		for(int j=2;j<=k;j++){
			cin>>kk>>t;
			cnt++;
			a[pt].push_back({cnt,0});
			a[cnt].push_back({pt,0});
			pt=cnt;
			a[pt].push_back({kk,t});
			a[kk].push_back({pt,t});
//			cout<<"        "<<kk<<" "<<pt<<"\n";
		}
	}
//	cout<<"\n\n\n";
//	for(int i=1;i<=cnt;i++){
//		cout<<i<<":\n";
//		for(auto j:a[i]){
//			cout<<"    "<<j.first<<" "<<j.second<<"\n";
//		}
//	}
//	cout<<"\n\n\n";
	while(q--){
		ll sss,ttt;
		cin>>sss>>ttt;
		dij(sss,ttt);
		for(int i=1;i<=cnt;i++){
//			cout<<"dist"<<i<<" "<<dist[i]<<"\n";
		}
		cout<<w[sss]+w[ttt]+dist[ttt]<<"\n";
	}
	return 0;
}
//luogu_liuyuxiaozaizai

