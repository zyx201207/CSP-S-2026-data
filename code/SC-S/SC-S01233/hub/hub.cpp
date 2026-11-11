#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+17;
int C,T;
int n,k;
int ans;
int d[N],vis[N];
struct Edge{
	int to,next;
}e[N];
int head[N],tot;
void add(int u,int v){
	e[++tot].to=v;
	e[tot].next=head[u];
	head[u]=tot;
}
void dfs_pre(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(d[v]==0 && vis[v]==0){
			dfs_pre(v);
		}
	}
}
void dfs(int u){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(d[v]>d[u]+1){
			d[v]=d[u]+1;
			dfs(v);
		}
	}
}
void work1(){
	while(T--){
		cin>>n>>k;
		ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++) head[i]=0;
		tot=0; 
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);add(v,u);
		}
		for(int sta=0;sta<(1<<n);sta++){
			int cnt=0;
			for(int i=0;i<n;i++) if((sta>>i)&1) cnt++;
			if(cnt!=k) continue;
			for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
			for(int i=0;i<n;i++) if((sta>>i)&1) d[i+1]=0;
			cnt=0;
			for(int i=1;i<=n;i++) vis[i]=0;
			for(int i=1;i<=n;i++){
				if(d[i]==0 && !vis[i]) dfs_pre(i),cnt++;
			}
			if(cnt>2) continue;
			for(int i=1;i<=n;i++){
				if(d[i]==0) dfs(i);
			}
			int anss=0;
			for(int i=1;i<=n;i++) anss=max(anss,d[i]);
			if(anss<ans){
				ans=anss;
//				cout<<sta<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
}
//void work2(){
//	while(T--){
//		cin>>n>>k;
//		int x,y;
//		for(int i=1;i<n;i++) cin>>x>>y;
//		m=n/2;
//		if(k==n) cout<<0<<'n';
//		else if(k>=m) cout<<1<<'\n';
//		if(k==1) cout<<m/2+1<<'\n';
//		else if(m&1){
//			l=(m+1)/2;
//			l=(l+1)/2;
//			r=(m+1)/2;
//			r=(r+m+1)/2;
//			if((m/2)&1){
//				if(k&1){
//					k=k/2;
//					if(k&1) cout<<l-(k/2)<<'\n';
//					else cout<<l-(k/2)<<'\n';
//				}else{
//					k=k/2;
//					if(k&1) cout<<l-(k/2)<<'\n';
//				}
//			}
//		}
////		int m=n/2;
////		m=m/k;
////		m=(m+1)/2+1;
////		cout<<m<<'\n';
//	}
//}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	if(C<=3) work1(); 
//	if(C>12 && C<15) work2();
//	work2();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/