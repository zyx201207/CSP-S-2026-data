#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;

long long c,T,n,d,ans,last,cnt,p,dist[maxn],tot[maxn],u,a[maxn];

struct pts{
	int idx,dist;
	bool operator<(const pts&x)const{
		return x.dist<dist;
	}
};

void bfs(int x){
	priority_queue<pts> q;
	for(int i=1;i<=n;i++){
		dist[i]=1e9;
		tot[i]=1;
	}
	dist[x]=0;
	q.push({x,0});
	while(!q.empty()){
		u=q.top().idx;
		q.pop();
		if(vis[u]){
			continue;
		}
		for(int i=1;i<=n;i++){
			if(i!=u&&abs(a[i]-a[u])<=d){
				if(dist[v]==dist[u]+1){
					tot[v]+=tot[u];
				}
				if(dist[v]>dist[u]+1){
					tot[v]=tot[u];
				}
			}
		}
	}
}

void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(tot[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
//	freopen("migrate3.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>c>>T;
	while(T--){
		work();
	}
	return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/

