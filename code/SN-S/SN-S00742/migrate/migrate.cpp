#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=10010;
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}return ans*f;
}
long long c,t,n,d,x[N],dis[M],cnt[M],vis[M],ans,u,v,w;
vector<long long>g[M];
void solve(){
	n=read(),d=read();
	if(n<=10000){
		ans=0;
		for(int i=1;i<=n;++i){
			g[i].clear();
			x[i]=read();
		}for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
				}
			}
		}for(int k=1;k<=n;++k){
			queue<long long>q;
			dis[k]=vis[k]=0;
			cnt[k]=1;
			for(int i=k+1;i<=n;++i){
				vis[i]=0;
				dis[i]=1e9;
				cnt[i]=0;
			}q.push(k);
			while(q.size()){
				u=q.front();q.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(auto v:g[u]){
					if(dis[v]>dis[u]+1){
						cnt[v]=cnt[u];
						dis[v]=dis[u]+1;
						q.push(v);
					}else if(dis[v]==dis[u]+1){
						cnt[v]+=cnt[u];
					}
				}
			}
			for(int i=k;i<=n;++i){
				ans+=(cnt[i]==2);
			}
		}cout<<ans<<'\n';
		return; 
	}cout<<0<<'\n';
	return;
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)solve(); 
	return 0;
} 
