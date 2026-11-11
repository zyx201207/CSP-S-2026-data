#include<bits/stdc++.h>
using namespace std;
int n,stp,cnt;
long long a[310],d;
bool vis[310];
struct node{
	int x,step;
};
int bfs(int x,int y){
	memset(vis,0,sizeof vis);
	queue<node> q;
	q.push({x,0});
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(vis[now.x]) continue;
		vis[now.x]=1;
		if(now.x==y){
			return now.step;
		}
		for(int i=1;i<=n;i++)
			if(i!=now.x&&abs(a[i]-a[now.x])<=d)
				q.push({i,now.step+1});
	}
	return 0;
}
void dfs(int x,int step,int tgt){
	if(step>stp||cnt>2) return;
	if(x==tgt){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(i!=x&&abs(a[i]-a[x])<=d)
			dfs(i,step+1,tgt);
}
bool chk(int x,int y){
	stp=bfs(x,y),cnt=0;
	dfs(x,0,y);
	return cnt==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(chk(i,j)) ans++;
		cout<<ans<<endl;
	}
}