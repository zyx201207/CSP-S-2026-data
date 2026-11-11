#include<bits/stdc++.h>
using namespace std;
long long x[2000010],f[2000010],f1[2000010];
vector<long long> g[2000010];
long long vis[2010][2010];
void dfs(long long u){
	for(auto v:g[u]){
		if(f[v]<=f[u]+1) continue;
		f[v]=f[u]+1;
//		if(v==3) cout<<u<<" ";
		dfs(v);
	}
	return ;
}
void dfs2(long long u){
	for(auto v:g[u]){
		if(f[v]!=f[u]+1) continue;
		if(vis[v][u]!=0)f1[v]+=(f1[u]-vis[v][u]);
		else f1[v]+=f1[u];
		vis[v][u]=f1[u];
		dfs2(v);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			g[i].clear();
			cin>>x[i];
		}
		for(long long i=1;i<=n;i++){
			long long l=i,r=n;
			while(r-l>=1){
				long long mid=(l+r+1)>>1;
				if(x[mid]-x[i]<=d){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
//			cout<<l<<" "<<r<<"\n";
			for(long long j=i+1;j<=l;j++){
				g[i].push_back(j);
			}
		}
//		cout<<"\n";
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			memset(f,0x3f,sizeof f);
			memset(f1,0,sizeof f1);
			memset(vis,0,sizeof vis);
			f[i]=0;
			f1[i]=1;
			dfs(i);
			dfs2(i);
//			cout<<"!";
			for(long long j=i+1;j<=n;j++){
				if(f1[j]==2) cnt++;
//				cout<<f[j]<<" ";
			}
//			cout<<"\n";
		}
		cout<<cnt<<"\n";
	}
	return 0;
}