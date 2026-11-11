#include<bits/stdc++.h>
#define int long long
#define N 2145140
#define pii std::pair<int,int>
#define elif else if
const int inf=0x66ccff66ccff;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		s=s*10+(c-'0');
		c=getchar();
	}
	return s*f;
}
std::vector<int> g[N];
int vis[N],vs[N];
int n,k,ans;
int c,_;

void dfs0(int u,int fa){
	vis[u]=1;
	for(auto &v:g[u]){
		if(v==fa)continue;
		if(vs[v])dfs0(v,u);
	}
}
int ret=inf;
void dfs2(int u,int fa,int dep){
	if(vs[u])ret=std::min(ret,dep);
	for(auto &v:g[u]){
		if(v==fa)continue;
		dfs2(v,u,dep+1);
	}
}

void cl(){for(int i=1;i<=n;++i)vis[i]=vs[i]=0;}
void solve(){
	ans=inf;
	for(int mask=0;mask<(1<<n);++mask){
		if(__builtin_popcount(mask)==k){
			for(int i=1;i<=n;++i)vs[i]=(mask>>(i-1))&1;
//			printf("\n");
			int cnt=0;
			for(int i=1;i<=n;++i){
				if(!vs[i])continue;
				if(!vis[i]){
					dfs0(i,0);cnt++;
				}
			}			
			if(cnt>2){cl();continue;}
//			for(int i=1;i<=n;++i)printf("%lld ",vs[i]);
			int res=0;
			for(int i=1;i<=n;++i){
				if(vs[i])continue;
				ret=inf;
				dfs2(i,0,0);
//				printf("(%lld),%lld\n",i,ret); 
				res=std::max(ret,res); 
			}
			ans=std::min(ans,res);
			cl();
		}
	} 
}
void clear(){
	for(int i=1;i<=n;++i)vis[i]=vs[i]=0;
	for(int i=1;i<=n;++i)g[i].clear();
	ans=inf;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),_=read();	
	while(_--){
		n=read(),k=read();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n){
			printf("0\n");
			continue;	
		}
		solve();
		printf("%lld\n",ans);
		clear();
	}
	return 0;
}
// 15pts 18:07
// ½ñÄê»áÓ®Âð£¿ 
/*
0 3

8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8

6 5
1 2
2 5
4 5
5 3
3 6





0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/

