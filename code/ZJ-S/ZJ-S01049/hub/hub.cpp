#include<bits/stdc++.h>
using namespace std;
int n,k,b[1000010],ans,d[1000010];
vector<int>g[1000010];
void dfs(int x){
	d[x]=1;
	for(auto &y : g[x])if(b[y]&&!d[y])dfs(y);
}
bool check(){
	if(k==2)return 1;
	int cnt=0;
	for(int i=1;i<=n;i++)d[i]=0;
	for(int i=1;i<=n;i++)if(!d[i]&&b[i])dfs(i),cnt++;
	return cnt<=2;
}
int get(){
	int res=0;
	for(int i=1;i<=n;i++)d[i]=0x3f3f3f3f;
	queue<int>q;
	for(int i=1;i<=n;i++)if(b[i])d[i]=0,q.push(i);
	while(q.size()){
		int x=q.front();q.pop();
		res=max(res,d[x]);
		for(auto &y : g[x])if(d[y]>d[x]+1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return res;
}
void dfs(int x,int kk){
	if(kk+n-x+1<k)return;
	if(kk>k)return;
	if(x>n){
		if(check())ans=min(ans,get());
		return;
	}
	dfs(x+1,kk);
	b[x]=1;
	dfs(x+1,kk+1);
	b[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,_;cin>>c>>_;
	while(_--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ans=0x3f3f3f3f;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
