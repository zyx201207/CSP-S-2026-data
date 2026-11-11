#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,wq;
int u,w,eu,ew;
int c1;
int c2;
int k;
int mk[500007]; 
int dis[500007];
struct lsqxx{
	int nex;
	int to;
	int sc;
}a[5000007];
int head[500007];
int vis[500007];
int idx;
void add(int c1,int c2,int c3){
	idx++;
	a[idx].sc = c3;
	a[idx].to = c2;
	a[idx].nex = head[c1];
	head[c1] = idx; 
} 
void spfa(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int kl = head[v];kl != 0;kl = a[kl].nex){
			if(dis[v] + a[kl].sc < dis[a[kl].to]){
				dis[a[kl].to] = dis[v] + a[kl].sc;
				q.push(a[kl].to);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>wq;
	for(int i = 1;i<=m;i++) cin>>mk[i];
	for(int i = 1;i<=n;i++){
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>vis[j]>>dis[j];
			for(int ij = 1;ij<j;ij++){
				add(vis[ij],vis[j],dis[j] + dis[ij]);
				add(vis[j],vis[ij],dis[j] + dis[ij]);
			}
		}
	}
	while(wq--){
		cin>>c1>>c2;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[c1] = 0;
		spfa(c1);
		cout<<(mk[c1]+mk[c2]+dis[c2])<<endl;
	}
	return 0;
}

