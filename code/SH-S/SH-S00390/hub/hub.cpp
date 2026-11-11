#include<bits/stdc++.h>
#define pii pair < int , int >
#define mp(a,b) make_pair(a,b) 
using namespace std;
const int MAXN = (2e1+5);
const int INF = (1e9);
int c,t,n,k,fa[MAXN],u[MAXN],v[MAXN],l,mx,ans,mn;
vector < int > V[MAXN];
int lowbit(int x){
	return (x&(-x));
} 
int cnt(int x){
	int s = 0;
	while(x){
		x -= lowbit(x);
		s++;
	}
	return s;
}
int dis(int x,int y){
	int u,v,w;
	bool vis[MAXN];
	memset(vis,0,sizeof(vis));
	queue < pii > Q;
	vis[x] = 1;
	Q.push(mp(x,0));
	while((!Q.empty())){
		u = Q.front().first;
		w = Q.front().second;
		Q.pop();
		if(u == y){
			break;
		}
		for(int i = 0;i < V[u].size();i++){
			v = V[u][i];
			if((!vis[v])){
				vis[v] = 1;
				Q.push(mp(v,(w+1)));
			}
		}
	}
	return w;
}
int find(int x){
	if(fa[x] == x){
		return x;
	}
	else{
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans = INF;
		cin>>n>>k;
		if(c <= 3){
			for(int i = 1;i <= n;i++){
				V[i].clear();
			}
			for(int i = 1;i < n;i++){
				cin>>u[i]>>v[i];
				V[u[i]].push_back(v[i]);
				V[v[i]].push_back(u[i]);
			}
			for(int i = 1;i < (1<<n);i++){
				if(cnt(i) == k){
					l = k;
					for(int j = 1;j <= n;j++){
						fa[j] = j;
					}
					for(int j = 1;j < n;j++){
						if(((i>>(u[j]-1))&1) && ((i>>(v[j]-1))&1)){
							if(find(u[j]) != find(v[j])){
								fa[u[j]] = v[j];
								l--;
							}
						}
					}
					if(l <= 2){
						mx = 0;
						for(int j = 1;j <= n;j++){
							if(((i>>(j-1))&1)){
								mn = 0;
							}
							else{
								mn = INF;
								for(int l = 1;l <= n;l++){
									if(((i>>(l-1))&1)){
										mn = min(mn,dis(j,l));
									}
								}
							}
							mx = max(mx,mn); 
						}
						ans = min(ans,mx);
					}
				}
			}
			cout<<ans<<endl;
		} 
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}
