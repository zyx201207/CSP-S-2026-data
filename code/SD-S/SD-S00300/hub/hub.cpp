#include<bits/stdc++.h>
using namespace std;
int n,K;
struct node{
	int nex,to;
}e[2000005];
int tot;
int he[1000005];
inline void add(int x,int y){
	e[++tot].nex=he[x];
	e[tot].to=y;
	he[x]=tot;
	return;
}
int col[1000005];
int cnt;
int dep[1000005];
int f[1000005][21];
int C,T;


inline void clear(){
	for (int i=1;i<=n;i++){
		he[i]=0;
	}
	tot=1;
	return;
}


inline void predfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for (int i=1;i<=20;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for (int i=he[x];i;i=e[i].nex){
		int v=e[i].to;
		if (v==fa){
			continue;
		}
		predfs(v,x);
	}
	return;
}
inline void dfs(int x,int fa){
	if (col[x] && (!col[fa])){
		cnt++;
	}
	for (int i=he[x];i;i=e[i].nex){
		int v=e[i].to;
		if (v==fa){
			continue;
		}
		dfs(v,x);
	}
	return;
}
inline int lca(int x,int y){
	if (dep[x]<=dep[y]){
		swap(x,y);
	}
	for (int i=20;i>=0;i--){
		if (dep[f[x][i]>=dep[y]]){
			x=f[x][i];
		}
	}
	if (x==y){
		return x; 
	}
	for (int i=20;i>=0;i--){
		if (f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
inline int calc(int S){
	for (int i=0;i<n;i++){
		if (S>>i&1){
			col[i+1]=1;
		}
	}
	cnt=0;
	dfs(1,0);
	if (cnt>2){
		for (int i=0;i<n;i++){
			if (S>>i&1){
				col[i+1]=0;
			}
		}
		return n+1;
	}	
	int res=0;
	for (int i=1;i<=n;i++){
		int ps=n+1;
		if (col[i]){
			continue;
		}
		for (int j=1;j<=n;j++){
			if (col[j]){
				ps=min(ps,dep[j]+dep[i]-2*dep[lca(i,j)]);
			}
		}
		res=max(res,ps);
	}
	for (int i=0;i<n;i++){
		if (S>>i&1){
			col[i+1]=0;
		}
	}
	return res;
}
inline int check(int x,int mm){
	int ll=x;
	int rr=mm-x+1;
	if (rr-ll+1-((x-1)*2)<=K){
		return 1;
	}
	return 0;
}

int d[1000005];
int lim;
inline void DFS(int x,int fa){
	for (int i=he[x];i;i=e[i].nex){
		int v=e[i].to;
		if (v==fa){
			continue;
		}
		DFS(v,x);
		if (!col[v]){
			d[x]=max(d[x],d[v]+1);
		}
		else{
			d[x]=max(d[x],0);
		}
	}
	if (d[x]>=lim){
		col[x]=1;
		d[x]=0;
		cnt++;
	}
	return;
}

inline int ck(int x){
	for (int i=1;i<=n;i++){
		col[i]=0;
		d[i]=0;
	}
	lim=x;
	cnt=0;
	DFS(1,0);
	if (cnt>K){
		return 0;
	}	
	cnt=0;
	dfs(1,0);
	if (cnt>2){
		return 0;
	}
	return 1;
}
inline void solve(){
	clear();
	cin>>n>>K;
	for (int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if (K==n){
		cout<<"0\n";
		return;
	}
	predfs(1,0);
	if (C<=3){
		int ans=n;
		for (int i=1;i<(1<<n);i++){
			if (__builtin_popcount(i)!=K){
				continue;
			}	
			ans=min(ans,calc(i));
		}
		cout<<ans<<"\n";
		return;
	}
	if (13<=C && C<=14){
		if (K==n){
			cout<<0<<"\n";
			return;
		}
		int mm=(n-1)/2;
		if (K>=mm){
			cout<<1<<"\n";
			return;
		}
		
		int l=2;
		int r=n;
		int ans=n;
		while (l<=r){
			int mid=(l+r)/2;
			if (check(mid,mm)){
				r=mid-1;
				ans=mid;	
			} 
			else{
				l=mid+1;
			}
		}
		cout<<ans<<"\n";
		return;
	}
	int l=0;
	int r=n;
	int ans=n;
	while (l<=r){
		int mid=(l+r)/2;
		if (ck(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<"\n";
	return;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>C>>T;
	while (T--){
		solve();
	}
	return 0;
}
