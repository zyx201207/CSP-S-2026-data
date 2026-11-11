#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll w[500005];
struct node{
	int F;ll S;
	bool operator<(const node&x)const{return x.S<S;}
};
vector<vector<node>> D(500005),G(505);
vector<vector<ll>> Len(505,vector<ll>(505,1e18));
void serve(int start){
	priority_queue<node> Q;
	Q.push({start,0});
	Len[start][start]=0;
	while(!Q.empty()){
		node tmp=Q.top();
		Q.pop();
		if(tmp.S>Len[start][tmp.F])continue;
		for(node u:G[tmp.F]){
			for(node v:D[u.F]){
				if(v.F==start)continue;
				ll need=u.S+G[v.F][v.S].S+Len[start][tmp.F];
				if(need<Len[start][v.F]){
					Len[start][v.F]=need;
					Q.push({v.F,need});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;ll t;cin>>a>>t; 
			G[i].push_back({a,t});
			D[a].push_back({i,j-1});
		}
	}
	for(int i=1;i<=n;i++){serve(i);}
	for(int i=1;i<=q;i++){
		int l,r;ll ans=1e18;cin>>l>>r;
		for(node a:D[l]){
			for(node b:D[r]){
				ans=min(ans,Len[a.F][b.F]+G[a.F][a.S].S+G[b.F][b.S].S+w[l]+w[r]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/