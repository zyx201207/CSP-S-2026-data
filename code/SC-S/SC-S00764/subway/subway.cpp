#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c,n,m,d,q,w[510],sta[510],dp[510][510],zt[510];
struct node{
	ll v,xl,time;
};
vector<node>ve;
struct node2{
	ll r,time;
};
vector<node2>lu[510];
void floyd(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int x = 1;x <= n;x++){
				dp[i][j] = min(dp[i][j],dp[i][x]+dp[x][j]); 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	memset(dp,0x3f,sizeof(dp));
	memset(zt,0x3f,sizeof(zt));
	for(ll i = 1;i <= n;i++){
		dp[i][i]=0;
		ll k,u,e;
		cin >> k;
		for(ll j = 1;j <= k;j++){
			cin >> u >> e;
			zt[u]=min(zt[u],e);
			sta[u]=i;
			ve.push_back({u,i,e});
		}
	}
	for(int i = 1;i < ve.size()-1;i++){
		for(int j = i+1;j < ve.size();j++){
			node n1=ve[i],n2=ve[j];
			if(n1.v == n2.v){
				lu[n1.xl].push_back({n2.xl,n1.time+n2.time});
				lu[n2.xl].push_back({n1.xl,n1.time+n2.time});
				dp[n1.xl][n2.xl] = min(dp[n1.xl][n2.xl],n1.time+n2.time);
				dp[n2.xl][n1.xl] = min(dp[n2.xl][n1.xl],n1.time+n2.time);
				
			}
		}
	}
//	for(int i = 1;i <= n;i++){
//		cout<<i<<"->";
//		for(node2 j : lu[i]){
//			cout<<j.r<<"="<<j.time<<endl;
//		}
//	}
	floyd();
//	for(int i = 1;i<= n;i++){
//		for(int j =1;j <= n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i = 1;i <= q;i++){
		ll oo,xx;
		cin >> oo >> xx;
		cout<<dp[sta[oo]][sta[xx]]+w[oo]+w[xx]+zt[oo]+zt[xx]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/