#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define fr first
#define sc second
#define ls(p) (p<<1)
#define rs(p) ((p<<1)|1)

using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int const N=1e6+5;
int n,m,cnt,ans,k;
vector<int> g[N];
pii a[N];
int pc(int x){
	int res=0;
	while(x){
		res+=x&1;
		x>>=1;
	}
	return res;
}
int f[N],qwq,qaq,p[N];
int getf(int x){
	if(x==f[x]) return f[x];
	return f[x]=getf(f[x]);
}
void dfs(int u,int fa,int w){
	if(p[u]){
		qaq=min(qaq,w);
		return;
	} 
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs(v,u,w+1);
	}
}
int const INF=1e9;
void sol(){
	n=read(),k=read();
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		g[u].pb(v);
		g[v].pb(u);
	}
	ans=INF;
	for(int s=0;s<(1<<n);s++){
		int x=pc(s);
		if(x==k){
			for(int i=1;i<=n;i++){
				f[i]=i;
				p[i]=0;
			}
			for(int i=1;i<=n;i++){
				if((1<<i-1)&s){
					p[i]=1;
					int u=i;
					for(auto v:g[u]){
						if((1<<v-1)&s){
							int x=getf(u),y=getf(v);
							f[x]=y;
						}
					}
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(f[i]==i&&p[i]) cnt++;
			}
			if(cnt>2) continue;
			qwq=0;
			for(int i=1;i<=n;i++){
				qaq=INF;
				dfs(i,0,0);
				qwq=max(qwq,qaq);
			}
			ans=min(ans,qwq);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		sol();
	}
	return 0;
}

