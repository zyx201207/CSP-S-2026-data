#include<bits/stdc++.h>
using namespace std;
int cccc,T,n,k,f[20],ans,ys[20],sss;
vector<int>a[100010];
int ld=0,l=0;
void dfs(int u,int fa,int step){
	if(step>l){
		l=step;
		ld=u;
	}
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(v==fa) continue;
		dfs(v,u,step+1);
	}
}
struct point{
	int step,fa,u;
};
int bfs(int o){
	queue<point>q;
	q.push({0,0,o});
	while(!q.empty()){
		point aaa=q.front();
		int u=aaa.u,fa=aaa.fa,step=aaa.step;
		q.pop();
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i];
			if(v==fa) continue;
			if(f[v]) return step+1;
			q.push({step+1,u,v});
		}
	}
	return 100000;
}
void rs(int u,int fa){
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(v==fa) continue;
		if(f[v]){
			ys[v]=sss;
			rs(v,u);
		}
	}
}
void check(){
	sss=0;
	for(int i=1;i<=n;i++){
		if(f[i]&&!ys[i]){
			ys[i]=++sss;
			rs(i,0);
		}
	}
	if(sss>2) return ;
	int ss=0;
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		ss=max(ss,bfs(i));
	}
	ans=min(ans,ss);
	
}
void ddfs(int u){
	if(u==k+1){
		memset(ys,0,sizeof(ys));
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			ddfs(u+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cccc>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(n<=10){
			ans=100000000;
			ddfs(1);
			cout<<ans<<endl;
		}
		else{
			ld=l=0;
			dfs(1,0,0);
			l=0;
			dfs(ld,0,0);
//			cout<<l<<endl;
			while(k){
				l=ceil(l*1.0/2);
				k--;
			}
			cout<<l<<endl;
		}
		for(int i=1;i<=n;i++) a[i].clear();
	}
	return 0;
}
