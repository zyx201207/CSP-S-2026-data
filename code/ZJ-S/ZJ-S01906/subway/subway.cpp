#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[200010];
int k,a[200010],t[200010];
int xr,yr;
int b=0,pre[200010];
struct node{
	int from,to,len,next;
}edge[20000010];
void add(int u,int v,int l){
	edge[++b]={u,v,l,pre[u]};
	pre[u]=b;
}
bool f[200010];
int dis[200010];
queue<int> qq;
int spfa(int s,int e){
	for(int i=1;i<=m;i++){
		f[i]=false;
		dis[i]=0x3f3f3f3f;
	}
	f[s]=true;
	qq.push(s);
	dis[s]=0;
	while(!qq.empty()){
		int u=qq.front();
		qq.pop();
		f[u]=false;
		for(int i=pre[u];i!=0;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].len){
				dis[v]=dis[u]+edge[i].len;
				if(!f[v]){
					qq.push(v);
					f[v]=true;
				}	
			}
		}
	}
	return dis[e];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int g=1;g<j;g++){
				add(a[g],a[j],t[g]+t[j]);
				add(a[j],a[g],t[g]+t[j]);
			}
		}
	}
	while(q--){
		cin>>xr>>yr;
		int ans=w[xr]+w[yr];
		ans+=spfa(xr,yr);
		cout<<ans<<"\n";
	}
	return 0;
}