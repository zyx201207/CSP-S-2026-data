#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k;
int vis[N],p[N],f[N];
vector<int> a[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int u,int v){
	int tx=find(u);
	int ty=find(v);
	if(tx!=ty){
		f[tx]=ty;
	}
}
bool bj[N];
void dfss(int u,int fa){
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(bj[u]&&bj[v]){
			merge(u,v);
		}
		if(v!=fa){
			dfss(v,u);
		}
	}
}
int d3[N];
void dfs3(int u,int fa){
	d3[u]=d3[fa]+1;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(v!=fa){
			dfs3(v,u);
		}
	}
}
int mn=1e9;
void dfs(int x){
	if(x==k+1){
		for(int i=1;i<=n;i++){
			f[i]=i;
			bj[i]=0;
		}
		for(int i=1;i<=k;i++){
			bj[p[i]]=1;
		}
		dfss(1,0);
		int cnt=0;
		int mn1=1e9,mn2=1e9;
		for(int i=1;i<=n;i++){
			if(bj[i]){
				if(find(i)==i){
					cnt++;
					if(cnt>2) return;
				}
			}
		}
		int qy=-1e9;
		for(int i=1;i<=n;i++){
			dfs3(i,0);
			int mnn=1e9;
			for(int j=1;j<=k;j++){
				mnn=min(d3[p[j]]-1,mnn);
			}
			qy=max(qy,mnn);
		}
		mn=min(mn,qy);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
  	freopen("hub.in","r",stdin);
  	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		mn=1e9;
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(c>=4){
			int hf=(n-1)/2;
			int p=(hf+k-1)/k;
			if(k>=hf){
				cout<<1<<'\n';
				continue;
			}
			if(k>=hf/2){
				cout<<2<<'\n';
			}else{
				cout<<hf/(k+1)+1<<'\n';
			}
			continue;
		}
		dfs(1);
		cout<<mn<<'\n';
	}
	return 0;
}
