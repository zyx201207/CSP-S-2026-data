#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,f[1000005][2],g[1000005],k,ans=1e9;
bool use[1000005];
vector<int>go[1000005];
int jy(int now,int fa){
	//cout << now << endl;
	int re=0;
	if(fa==0){
		if(use[now]){
			re=1;
		}
	}
	for(int v : go[now]){
		if(v==fa)continue;
		if(use[now])re+=jy(v,now);
		if(!use[now] && use[v]){
			re+=jy(v,now)+1;
		}
		if(!use[now] && !use[v])re+=jy(v,now);
	}
	return re;
}
void dfs1(int now,int fa){
	if(use[now])f[now][0]=f[now][1]=0;
	for(int v : go[now]){
		if(v==fa)continue;
		dfs1(v,now);
		if(f[v][0]+1<=f[now][0]){
			f[now][1]=f[now][0];
			f[now][0]=f[v][0]+1;
		}
		else if(f[v][0]+1<f[now][1]){
			f[now][1]=f[v][0]+1;
		}
	}
}
void dfs2(int now,int fa){
	for(int v : go[now]){
		if(v==fa)continue;
		if(f[v][0]+1==f[now][0]){
			g[v]=min(g[v],f[now][1]+1);
		}
		else{
			g[v]=min(g[v],f[now][0]+1);
		}
		g[v]=min(g[v],g[now]+1);
		dfs2(v,now);
	}
}
int js(){
	if(jy(1,0)>2){
		//cout << "hello" << endl;
		return 1e9;
	}
	//cout << jy(1,0) << endl;
	//cout << "ok" << endl;
	for(int i=1;i<=n;i++){
		f[i][0]=f[i][1]=g[i]=1e9;
	}
	dfs1(1,0);
	dfs2(1,0);
	int re=0;
	for(int i=1;i<=n;i++){
		re=max(re,min(g[i],f[i][0]));
	}
	/*
	cout << re << endl;
	for(int i=1;i<=n;i++){
		cout << use[i] << " ";
	}
	cout << endl;
	for(int i=1;i<=n;i++){
		if(f[i][0]!=1e9){
			cout << f[i][0] << " ";
		}
		if(g[i]!=1e9){
			cout << g[i];
		}
		//cout << endl;
	} 
	//cout << endl << endl;
	//if(re==1){
		//cout << "here" << endl;
	//}
	*/
	return re;
}
void dfs(int now,int cnt){
	if(now>n){
		ans=min(ans,js());
		return;
	}
	if(k-cnt>0){
		use[now]=1;
		dfs(now+1,cnt+1);
		use[now]=0;
	}
	if(n-now+1>k-cnt){
		dfs(now+1,cnt);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans=1e9;
		cin >> n >> k;
		for(int i=1;i<=n;i++)go[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			go[u].push_back(v);
			go[v].push_back(u);
		}
		dfs(1,0);
		cout << ans <<endl;
	}
}