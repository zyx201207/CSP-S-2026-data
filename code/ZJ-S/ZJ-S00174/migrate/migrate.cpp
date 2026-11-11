#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,far[N],sum;
long long x[N],dis[305][305];
vector<int> g[N];
void dfs(int u,int s,int mb,int ms){
	if(sum==-1) return;
	if(u==mb){
		if(s==ms) sum++;
		if(sum>=3){
			sum=-1;
			return;
		}
	}
	if(s+dis[u][mb]>ms) return;
	for(int j=u+1;j<=far[u];j++){
		dfs(j,s+1,mb,ms);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i],far[i]=-1;
		if(c<=10){
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<=n;i++){
				long long s=0;
				for(int j=i+1;j<=n;j++){
					s+=(x[j]-x[j-1]);
					if(s>d){
						far[i]=j-1;
						break;
					}
				}
				if(far[i]==-1) far[i]=n;
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) dis[i][j]=-1;
			for(int i=1;i<=n;i++){
				int s=0;
				dis[i][i]=0;
				for(int j=i;j<=n;j=far[j]){
					s++;
					if(j==far[j]) break;
					for(int k=j+1;k<=far[j];k++){
						dis[i][k]=s;
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dis[i][j]==-1) break;
					sum=0;
					dfs(i,0,j,dis[i][j]);
					if(sum==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			int s=0;
			long long tot=0;
			for(int i=2;i<=n;i++){
				tot+=(x[i]-x[i-1]);
				if(tot>d) break;
				s++;
			}
			if(s==0 || s==1) cout<<0<<'\n';
			else{
				long long ans=0;
				for(int i=1;i<=n;i++){
					int ss=(n-i+1)/s-1;
					if(ss==-1) ss=0;
					ans+=ss;
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}