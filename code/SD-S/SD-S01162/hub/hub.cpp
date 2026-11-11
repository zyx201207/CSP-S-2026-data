#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1001000,inf=0x3f3f3f3f;
int c,t,n,k,head[N],cnt,b[N],vis[N],maxdep,maxid;
struct node{
	int v,nxt;
}e[2*N];
void add(int u,int v){
	e[++cnt]={v,head[u]},head[u]=cnt;
}
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(b[v]&&!vis[v])dfs(v);
	}
}
int dfs1(int u,int fa,int dep){
	int ans=inf;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)continue;
		if(b[v])return dep+1;
		ans=min(ans,dfs1(v,u,dep+1));
	}
	return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;cnt=0;
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		int ans=inf;
		if(c<=3){
			for(int mask=0;mask<(1<<n);mask++){
				int tot=0,sum=0,d=0;
				for(int i=0;i<n;i++){
					if((mask>>i)&1)tot++,b[i+1]=1;
					else b[i+1]=0;
				}
				if(tot!=k)continue;
				for(int i=1;i<=n;i++)vis[i]=0;
				for(int i=1;i<=n;i++)if(b[i]&&!vis[i])sum++,dfs(i);
				if(sum!=2)continue;
				for(int i=1;i<=n;i++){
					if(!b[i])d=max(d,dfs1(i,0,0));
				}
				ans=min(ans,d);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//215pts kskblzdjd
//freoepn feropen froeepn freopne 
