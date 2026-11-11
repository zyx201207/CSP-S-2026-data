#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int N=5e3+5,M=N*N/2;
long long c,t,x[N],j[N],ne[M],head[N],to[M],num,wi[M],dis[N];
bool vis[N];
priority_queue<pair<int,int> >q;
void add(int u,int v,int w){
	ne[num]=head[u];
	to[num]=v;
	wi[num]=w;
	head[u]=num++;
}
void dfs(int now,int lo,int step){
	bool st[N];
	memset(st,0,sizeof(st));
	if(step>dis[lo])return;
	if(now==lo){
		if(step==dis[lo]){
			j[lo]++;
		} 
		return;
	}
	for(int i=head[now];i!=-1;i=ne[i]){
		if(!st[to[i]]){
			st[to[i]]=1;
			dfs(to[i],lo,step+wi[i]);
			st[to[i]]=0;
	}
	}	
}
void dij(int n){
	int cnt=0;
	for(int l=1;l<=n;l++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(j,0,sizeof(j));
		dis[l]=0;
		q.push({0,l});
		while(!q.empty()){
			int now=q.top().second;
			q.pop();
			vis[now]=1;
			for(int i=head[now];i!=-1;i=ne[i]){
				int t=to[i];
				int w=wi[i];
				if(dis[i]+w<dis[t]){
					dis[t]=dis[i]+w;
					if(!vis[t])q.push({-dis[t],t});
				}
			}
		}
		for(int i=1;i<=n;i++){
			dfs(l,i,0);
			if(j[i]==2)cnt++;
		}
	}
		cout<<cnt<<endl;
}
int main(){
	cin>>c>>t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out ","w",stdout);
	while(t--){
		memset(head,-1,sizeof(head));
		memset(ne,0,sizeof(ne));
		memset(wi,0,sizeof(wi));
		memset(to,0,sizeof(to));
		num=0;
		long long n,d,ans;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					add(i,j,abs(x[i]-x[j]));
					add(j,i,abs(x[i]-x[j]));
				}
			}
		}
		dij(n);
	} 
	return 0;
}