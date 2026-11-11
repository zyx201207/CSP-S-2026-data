#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long n,c,t,d,a[N],fa[N],ans=0,ansf=0,vis[N];
struct node{
	long long x,d;
};
vector<node> e[N];
void dfs(long long u,long long f,long long cnt){
	for(auto v:e[u]){
		if(v.x==u||vis[v.x]==1) continue;
		vis[v.x]=1;
		dfs(v.x,u,cnt+v.d);
		vis[v.x]=0;
	}
	if(cnt<=ans) ans=cnt;
	return ;
}
bool dfs2(long long u,long long f,long long cnt){
	for(auto v:e[u]){
		if(v.x==u||vis[v.x]==1) continue;
		vis[v.x]=1;
		dfs2(v.x,u,cnt+v.d);
		vis[v.x]=0;
	}
	if(cnt==ans) return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					//cout<<i<<' '<<j<<"\n";
					e[i].push_back({j,abs(a[i]-a[j])});
					e[j].push_back({i,abs(a[i]-a[j])});
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				ans=0;
				dfs(j,i,0);
				if(dfs2(j,i,0)==ans){
					ansf++;
				}
			}
		}
		cout<<ansf;
	} 
	return 0;
}