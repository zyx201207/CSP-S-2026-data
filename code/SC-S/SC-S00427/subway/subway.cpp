#include<bits/stdc++.h>
#define PI pair<int,int>
#define int long long 
using namespace std;

inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0',ch=getchar();}
	return f*x;
}
 
const int N=510,M=2e4+10;
vector<int> a[M];
vector<int> l[N];
int dis[N][M];
int c,n,m,d,q,w[M];
int id,t,k;

bool vis[M];
int s,e,ans=INT_MAX;
void dfs(int p,int lp,int sum){
	if(p==e){
		ans=min(ans,sum);
		return ;
	}
	
	vis[p]=true;
	for(int i=0;i<a[p].size();++i){
		int now=a[p][i];
		sum+=dis[now][p];
		
		for(int j=0;j<l[now].size();++j){
			int to=l[now][j];
			if(!vis[to]) dfs(to,now,sum+dis[now][to]);
		}
		sum-=dis[now][p];
	}
	vis[p]=false;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i){
		k=read();
		for(int j=1;j<=k;++j){
			id=read(),t=read();
			
			dis[i][id]=t; 
			l[i].push_back(id);
			a[id].push_back(i);
		}
	}
	
	
	for(int i=1;i<=q;++i){
		for(int j=1;j<=m;++j) vis[j]=false;
		s=read(),e=read();
		dfs(s,0,0);
		printf("%lld\n",ans+w[s]+w[e]);
	}
	return 0;
} 