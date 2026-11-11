#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn=5005;
const int inf=0x3f3f3f3f3f;
int T,c;
int n,d,a[maxn];
vector<int> e[maxn];
int dis[maxn],cnt[maxn];
bool vis[maxn];
bool pd[maxn][maxn];
void dij(int st){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dis[st]=0;
	cnt[st]=1;
	q.push({0,st});
	while(!q.empty()){
		pii t=q.top();q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({dis[v],v});
			}
			else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
	return ;
}
inline int read(){
	int num=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		num=num*10+(ch^48);
		ch=getchar();
	}
	return num*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			e[i].clear();
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(abs(a[j]-a[i])<=d){
					e[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) pd[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				if(dis[j]<inf&&cnt[j]==2){
					pd[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pd[i][j]) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}