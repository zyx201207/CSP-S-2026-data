#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=1e6+10;

int c,t,n,k;

int go[N][20],f[N],vis[N],dep[N],ff[N],dis[20][20],vvv[20];

vector<int> vt[N];

void dfs2(int u,int fa){
	go[u][0]=fa;
	for(int i=1;i<=10;i++){
		go[u][i]=go[go[u][i-1]][i-1];
	}
	dep[u]=dep[fa]+1;
	for(int i=0;i<vt[u].size();i++){
		int v=vt[u][i];
		if(v==fa) continue;
		dfs2(v,u);
	}
}

int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=4;i>=0;i--){
		if(dep[go[u][i]]>=dep[v]) u=go[u][i];
	}
	if(u==v) return u;
	for(int i=4;i>=0;i--){
		if(go[u][i]!=go[v][i]){
			u=go[u][i],v=go[v][i];
		}
	}
	return go[u][0];
}

int aa=0x3f3f3f3f;

int find(int x){
	if(x==ff[x]) return x;
	else return ff[x]=find(ff[x]);
}

void dfs(int x,int lst){
	if(x==k+1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ff[i]=i;vvv[i]=0;
		}
		for(int j=1;j<=k;j++){
			for(int i=j+1;i<=k;i++){
				if(dis[f[i]][f[j]]){
					ff[find(f[i])]=find(f[j]);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=k;i++){
			if(!vvv[find(f[i])]){
				vvv[find(f[i])]=1;cnt++;
			}
		}
		if(cnt>2) return ;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int res=0x3f3f3f3f;
			for(int j=1;j<=k;j++){
				int L=lca(i,f[j]);
				res=min(res,dep[i]+dep[f[j]]-2*dep[L]);
			}
			ans=max(ans,res);
		}
		aa=min(aa,ans);
		return ;
	}
	for(int i=lst+1;i<=n;i++){
		f[x]=i;vis[i]=1;
		dfs(x+1,i);
		vis[i]=0;
	}
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			vt[i].clear();
			f[i]=vis[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		if(n<=k){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			if(k>=n/2){
				cout<<"1\n";
			}else{
				cout<<n/2-k<<"\n";
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<vt[i].size();j++){
				dis[i][vt[i][j]]=dis[vt[i][j]][i]=1;
			}
		}
		aa=0x3f3f3f3f;
		dfs2(1,0);
		dfs(1,0);
		
		cout<<aa<<"\n";
	}
	
	return 0;
}

