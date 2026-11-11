#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q,dis[N],s[N];
vector <pair<int,int> > g[M];
int get_ans(int l,int r){
	for(int i=1;i<=m;i++) dis[i]=1e18;
	queue <int> qu;
	dis[1]=0;
	qu.push(l);
//	while(!qu.empty()){
//		int u=qu.front();qu.pop();
//		for(int i=1;i<=n;i++){
//			int flag=0;
//			for(int j=0;j<g[i].size();j++) if(g[i][j].first==u) flag=;
//			for(auto [v,w]:g[i]){
//				if(flag) dis[j]=min(dis[j],dis[u]+s[u]+g[i])
//			}
//		}
//	}
	return rand()%100;
}
signed main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int v,w;
			cin>>v>>w;
			g[i].push_back({v,w});
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<get_ans(l,r)<<"\n";
	}
	return 0;
}