//王浩澜 西安交通大学附属中学 SN-S00516
#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,a[1000005],dis[1000005],mx,mn;
bool us[1000005],vs[1000005];
vector<int> e[1000005];
queue<int> q;
int read(){
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			f=-1;
		if(c==EOF)
			return 0;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
void bfs(){
	mx=0;
	for(int i=1;i<=k;i++)
		q.push(a[i]),dis[a[i]]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vs[u]=1;
		for(int i=0;i<e[u].size();i++){
			if(!vs[e[u][i]]){
				dis[e[u][i]]=dis[u]+1;
				mx=dis[e[u][i]];
				q.push(e[u][i]);
			}
		}
	}
	mn=min(mn,mx);
}
void dfs(int now){
	if(now==k+1){
		bfs();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!us[i]){
			us[i]=1;
			a[now]=i;
			dfs(now+1);
			us[i]=0;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		mn=0x3f3f3f3f;
		dfs(1);
		cout<<mn<<"\n";
	}
	return 0;
}
