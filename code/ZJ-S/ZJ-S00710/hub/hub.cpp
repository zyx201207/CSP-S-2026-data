#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
//#define int long long

int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+(int)(c-'0');
		c=getchar();
	}
	return k*f;
}
struct node{
	int to,next;
}edge[2*maxn];
int vex[maxn],ei;
void add(int u,int v){
	edge[++ei]=node{v,vex[u]};
	vex[u]=ei;
}
int n,k,dep[maxn],ma[maxn];
void dfs1(int u,int fa){
	ma[u]=dep[u]=dep[fa]+1;
	for(int i=vex[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa){
			continue;
		}
		dfs1(v,u);
		ma[u]=max(ma[u],ma[v]);
	}
}
int num,f[maxn],cnt,ans;
int vis[maxn];
void dfs2(int u,int fa){
	vis[u]=1;
	int flag=1;
	for(int i=vex[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(dep[v]<dep[u]||f[v]==0){
			continue;
		}
		dfs2(v,u);
		flag=0;
	}
	if(flag){
//		cout<<u<<"()";
		cnt=max(cnt,ma[u]-dep[u]);
	}
} 
typedef pair<int,int> pii;
queue<pii> q1;
priority_queue<pii,vector<pii>,greater<pii> > q;
int a[20],si;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		n=read();
		k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			add(u,v);
			add(v,u);
		} 
//		ans=0x3f3f3f3f;
//		dfs1(1,0);
		if(k>=n){
			cout<<0<<endl;
			continue;
		}
		n/=2;
		n-=k;
		for(int i=0;i<=n;i++){
			if(4*i>=n){
				cout<<i+1<<endl;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);	
}
