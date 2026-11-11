#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,inf=1e9+7;
int n,k,u[N],v[N];
vector<int>g[N];
void work1(){
	int m=n/2;
	if(k==n){
		cout<<0<<"\n";
		return ;
	}
	if(k>=m){
		cout<<1<<"\n";
		return ;
	}
	int ans=0;
	for(int j=(1<<20);j;j>>=1)
	if(ans+j<=n&&k+(ans+j-1)*4<m)ans+=j;
	++ans;
	cout<<ans<<"\n";
	return ;
}
int dep[N],mx[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	mx[x]=dep[x];
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
		mx[x]=max(mx[x],mx[y]);
	}
	return ;
}
int dfs2(int x,int fa,int c,int w,int pt){
	if(!pt){
		int cnt=0;
		cnt+=(c+1>w);
		for(int y:g[x])
		if(y!=fa&&mx[y]-dep[y]+2>w)++cnt;
		if(cnt==0)return 0;
		int ret=1;
		for(int y:g[x])
		if(y!=fa)ret+=dfs2(y,x,0,w,0);
		return ret;
	}
	else{
		int cnt=0;

		for(int y:g[x])
		if(y!=fa&&mx[y]-dep[y]+2>w)++cnt;
		if(cnt==0)return 1;
		if(cnt==1&&c+1<=w){
			int ret=0,bb=0;
			for(int y:g[x])
			if(y!=fa&&mx[y]-dep[y]+2<=w)bb=max(bb,mx[y]-dep[y]+2);
		
			for(int y:g[x])
			if(y!=fa&&mx[y]-dep[y]+2>w)ret=dfs2(y,x,bb,w,1);
			return ret;
		}
		else{
			int ret=1;
			for(int y:g[x])
			if(y!=fa)ret+=dfs2(y,x,0,w,0);
			return ret;
		}
		
	}
	
}
bool check(int w){
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++)dep[j]=mx[j]=0;
		dfs(u[i],v[i]);
		dfs(v[i],u[i]);
		int tt=0;
		tt+=dfs2(u[i],v[i],0,w,1);
		tt+=dfs2(v[i],u[i],0,w,1);
		if(tt<=k)return true;
	}
	return false;
}
void work2(){
	if(k==n){
		cout<<0<<"\n";
		return ;
	}
	int ans=-1;
	for(int j=(1<<20);j;j>>=1)
	if(!check(ans+j))ans+=j;
	check(1);
	++ans;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid,T;cin>>cid>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		int ok=1;
		if(n%2==0)ok=0;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			u[i]=x,v[i]=y;
			g[x].push_back(y);
			g[y].push_back(x);
			if(i<=n/2&&(x!=i||y!=i+1))ok=0;
			if(i>n/2&&(x!=i-n/2||y!=i+1))ok=0;
		}
		if(ok)work1();
		work2();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
0 2
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

