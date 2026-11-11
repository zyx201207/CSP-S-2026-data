#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> tu[N];
int n,k,fa[N],f[N],d[N];
void add_edge(int u,int v){
	tu[u].push_back(v);
}
int getfa(int a){
	if (fa[a]!=fa[fa[a]]){
		return getfa(fa[a]);
	}
	return fa[a];
}
void merge(int a,int b){
	fa[a]=getfa(a);
	fa[b]=getfa(b);
	if (fa[a]!=fa[b]){
		fa[b]=fa[a];
	}
}
int count(int v){
	int cnt=0;
	while (v>0){
		cnt+=v%2;
		v/=2;
	}
	return cnt;
}
void dfs(int u,int fa,int dis){
	if (f[u]){
		d[u]=0;
	}else{
		d[u]=min(d[u],dis);
	}
	for (int i=0;i<tu[u].size();i++){
		if (tu[u][i]==fa){
			continue;
		}
		dfs(tu[u][i],u,dis+1-f[tu[u][i]]);
	}
}
void work(){
	int ans=INT_MAX;
	for (int i=0;i<(1<<n);i++){
		if (count(i)!=k){
			continue;
		}
		for (int j=1;j<=n;j++){
			fa[j]=j;
			f[j]=0;
			d[j]=INT_MAX;
		}
		for (int j=0;j<n;j++){
			if (((i>>j)&1==1)){
				f[j+1]=1;
			}
		}
		for (int j=1;j<=n;j++){
			if (f[j]){
				for (int k=0;k<tu[j].size();k++){
					if (f[tu[j][k]]==1){
						merge(j,tu[j][k]);
					}
				}
			}
		}
		int cnt=0;
		for (int j=1;j<=n;j++){
			if (f[j] && getfa(j)==j){
				cnt++;
			}
		}
		//cout<<cnt<<'\n';
		if (cnt>2){
			continue;
		}
		int tmp=0;
		for (int j=1;j<=n;j++){
			if (f[j] && getfa(j)==j){
				dfs(j,0,0);
			}
		}
		for (int j=1;j<=n;j++){
			//cout<<f[j]<<' '<<d[j]<<'\n';
			tmp=max(tmp,d[j]);
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while (T--){
		cin>>n>>k;
		for (int i=1;i<=n;i++){
			tu[i].clear();
		}
		for (int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			add_edge(u,v);
			add_edge(v,u);
		}
		if (C<=6){
			work();
		}else{
			cout<<int(ceil((n/2+2-k)*1.0/4))<<'\n';
		}
	}
	return 0;
}
