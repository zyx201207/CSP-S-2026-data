#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
int c,T;
int n,k;
struct node{
	int v,pre;
}a[maxn<<1];
int head[maxn];
int on;
void pu(int u,int v){
	a[++on].v = v;
	a[on].pre = head[u];
	head[u] = on;
}
int jh[35];
int book[35];
map<int,int> mp;
void dfs1(int u,int fa){
	book[u] = 1;
	for(int i=head[u];i;i=a[i].pre){
		int v =a[i].v;
		if(v!=fa&&mp[v]==1){
			dfs1(v,u);
		}
	}
}
bool pd(){
	int lt=0;
	for(int i=1;i<=n;i++)book[i]=0;
	for(int i=1;i<=k;i++){
		if(book[jh[i]]==0){
			lt++;
			dfs1(jh[i],0);
		}
	}
	return lt<=2;
}
int minn = 999999;
int dfs2(int u,int fa,int st){
	if(mp[u]==1)return st;
	int ans = 99999;
	for(int i=head[u];i;i=a[i].pre){
		int v = a[i].v;
		if(v==fa)continue;
		ans = min(ans,dfs2(v,u,st+1));
	}
	return ans;
}
int js(){
	int d = 0;
	for(int i=1;i<=n;i++){
		d = max(d,dfs2(i,-1,0));
	}
	return d;
}
void dfs(int id,int sum){
	if(sum>k)return;
	if(id==n+1){
		if(sum==k){
			if(pd()){
				minn = min(minn,js());
			}
		}
		return;
	}
	dfs(id+1,sum);
	jh[sum+1] = id;
	mp[id] = 1;
	dfs(id+1,sum+1);
	jh[sum+1] = 0;
	mp[id] = 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		minn = 99999999;
		cin>>n>>k;
		for(int i=1;i<=n;i++)head[i]=0;
		on=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			pu(u,v);
			pu(v,u);
		}
		//暴力
		 dfs(1,0);
		 cout<<minn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
