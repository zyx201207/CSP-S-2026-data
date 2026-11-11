#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50,inf=1e18+50;
int idx,head[N],ok[N];
struct p{
	int to,nxt;
}e[N];
int vis[1050];
void add(int u,int v){
	e[++idx].to=v;
	e[idx].nxt=head[u];
	head[u]=idx;
}
void dfs1(int u,int fa){
	if(vis[u]) return;
	vis[u]=1;
	for(int i=head[u];i!=0;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa || ok[v]==0 || vis[v]) continue;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa){
	if(vis[u]) return;
	vis[u]=1;
	for(int i=head[u];i!=0;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa || ok[v]==0 || vis[v]) continue;
		dfs2(v,u);
	}
}
int d[1050];
void dfs3(int u,int dep){
	if(d[u]<dep) return;
	d[u]=dep;
	for(int i=head[u];i!=0;i=e[i].nxt){
		int v=e[i].to;
		dfs3(v,dep+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	/*
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
	
	0 1
	8 6
	4 8
	5 8
	6 3
	3 2
	2 1
	1 8
	7 8
	
	*/
	
	while(T--){
		memset(head,0,sizeof head);
		for(int i=0;i<=idx;i++) e[i].to=e[i].nxt=0;
		idx=0;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int l,r;
			cin>>l>>r;
			add(l,r),add(r,l);
		}
		int ans=inf;

		for(int mask=0;mask<(1<<n);mask++){
			int root=0;
			int sum=0;
			memset(vis,0,sizeof vis);
			memset(ok,0,sizeof ok);
			for(int i=0;i<n;i++){
				if(mask&(1<<i)){
					ok[i+1]=1;
					root=i+1;
					sum++;
					
				}
				else ok[i+1]=0;
			}
			if(sum!=k) continue;
			
			dfs1(root,-1);
			int root2=0;
			for(int i=0;i<n;i++){
				if(mask&(1<<i) && vis[i+1]==0){
					root2=i+1;
				}
			}
			dfs2(root2,-1);
//			for(int i=1;i<=n;i++){
//				if(ok[i]) cout<<i<<" ";
//			}
//			cout<<'\n';
//			cout<<root<<" "<<root2<<" ";
//			cout<<'\n';
			int o=1;
			for(int i=0;i<n;i++){
				if(mask&(1<<i) && vis[i+1]==0){
					o=0;
//					cout<<i+1<<'\n';
				}
			}
//			cout<<"-------"<<'\n';
			if(o==0) continue;
			memset(d,0x3f,sizeof d);
			for(int i=0;i<n;i++){
				if(mask&(1<<i)){
					dfs3(i+1,0);
				}
			}
			int anser=0;
			for(int i=0;i<n;i++) anser=max(anser,d[i+1]);
			ans=min(anser,ans);
		}
		cout<<ans<<'\n';
	}
}
/*
0 1
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

0 1
5 2
1 2
2 3
3 4
4 5

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