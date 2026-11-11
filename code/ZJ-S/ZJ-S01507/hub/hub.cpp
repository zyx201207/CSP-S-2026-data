#include<bits/stdc++.h>
using namespace std;
int n,k,c,T,num,cnt,L,R;
const int N=1e6+10;
vector<int>G[N],son[N];
int d[N],imp[N],lian[N],dep[N],fa[N],maxd[N],vis[N];
void dfs1(int u,int dis){
	son[u].clear();maxd[u]=0;
	for(int v:G[u]){
		if(v==fa[u]) continue;
		dfs1(v,dis);
	    d[u]=max(d[u],d[v]+1);
	    if(imp[v]) son[u].push_back(v);
	    else maxd[u]=max(maxd[u],maxd[v]+1);
	}
	if(d[u]>=dis) imp[u]=1,num++;
	else imp[u]=0;
}
int calc(int dis){
	if(!cnt) return 0;
//	cerr<<"debuf "<<" "<<dis<<" "<<L<<" "<<R<<'\n';
//	for(int i=1;i<=cnt;i++) cerr<<lian[i]<<" ";cout<<'\n';
	int res=0;
	for(int i=1;i<=cnt;i++)
	for(int j=i;j<=cnt;j++){
		if(i==1&&j==cnt&&!L&&!R) continue;
		bool flag=true;
		for(int l=i;l<=j;l++){
			int mind=1e9;
			if(i!=1||L) mind=min(mind,l-i+1);
			if(j!=cnt||R) mind=min(mind,j-l+1);
//			cout<<i<<" "<<j<<" "<<l<<" "<<mind<<'\n';
			if(maxd[l]+mind>=dis){
				flag=false;
				break;
			} 
		}
		if(flag==true) res=max(res,j-i+1);
	}
//	cout<<res<<'\n';
	return num-res<=k;
}
vector<int>v[N];
int check(int dis){
    num=0;
	dfs1(1,dis);
	if(!num) return 1;
//	cerr<<"debug "<<dis<<'\n';
//		for(int i=1;i<=n;i++) cout<<imp[i]<<" "<<maxd[i]<<'\n';
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=n;i>=1;i--){
		if(v[i].size()==0) continue;
		for(int u:v[i])
		    if(imp[u]&&!vis[u]){
		        int cur=u;cnt=0;
		        if(son[cur].size()) L=1;else L=0;
		        while(!vis[cur]&&son[cur].size()<=1){
		        	vis[cur]=1;lian[++cnt]=maxd[cur];
		        	cur=fa[cur];
				}
			    if(imp[cur]) R=1;else R=0;
				if(calc(dis)) return 1;
		    }
	}
	if(son[1].size()==2){
		int cur=son[1][0];
		cnt=0;
		while(son[cur].size()<=1){
			lian[++cnt]=maxd[cur];
			if(son[cur].empty()) break;
			cur=son[cur][0];
		}
		if(son[cur].size()) L=1;else L=0; 
		reverse(lian+1,lian+cnt+1);lian[++cnt]=maxd[1];
		cur=son[1][1];
		while(son[cur].size()<=1){
			lian[++cnt]=maxd[cur];
		    if(son[cur].empty()) break;
			cur=son[cur][0];
		}
		if(son[cur].size()) R=1;else R=0;
		if(calc(dis)) return 1;
	}
	return 0;
}
void dfs0(int u,int f){
	dep[u]=dep[f]+1;fa[u]=f;
	v[dep[u]].push_back(u);
	for(int v:G[u]){
		if(v==f) continue;
		dfs0(v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear(),v[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);G[v].push_back(u);
	}
	if(k>=n){cout<<0;return;}
	dfs0(1,1);
//	cerr<<"debug\n";
	int l=1,r=n-1,p;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) p=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<p<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}