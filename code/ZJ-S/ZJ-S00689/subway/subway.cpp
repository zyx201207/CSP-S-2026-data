#include<bits/stdc++.h>
#define ll long long
using namespace std;//c与d没有用处 
ll c,n,m,d,q,W[500005],dis[505][505];
struct node{
	ll A,T;
};
vector<node> mp[505];
vector<node> mp2[500005];
int main(){
	for(int i=1;i<=501;i++){
		for(int j=1;j<=501;j++){
			dis[i][j]=1e18;
		}
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",W+i);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		while(k--){
			node t;
			scanf("%lld%lld",&t.A,&t.T);
			mp[i].push_back(t);
			mp2[t.A].push_back((node){i,t.T});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<mp[i].size();j++){
			ll t=mp[i][j].A;
			for(int k=0;k<mp2[t].size();k++){
				ll tt=mp2[t][k].A;
				if(tt!=i){
					dis[i][tt]=min(dis[i][tt],mp2[t][k].T+mp[i][j].T);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue; 
			for(int j=1;j<=n;j++){
				if(i==j||j==k) continue;
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	while(q--){
		ll a,b,ans=1e18;
		scanf("%lld%lld",&a,&b);
		for(int i=0;i<mp2[a].size();i++){
			for(int j=0;j<mp2[b].size();j++){
				if(mp2[a][i].A==mp2[b][j].A){
					ans=min(ans,mp2[a][i].T+mp2[b][j].T);
				}else{
					ans=min(ans,(dis[mp2[a][i].A][mp2[b][j].A]+mp2[a][i].T+mp2[b][j].T));
				}
			}
		}
		printf("%lld\n",(ans+W[a]+W[b]));
	}
	return 0;
}
