#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,inf=1e18;
int p[N],m,kkksc03;
int n,k;//最多选择k个点 
basic_string<int>e[N];
void find_p(){
	int d[N];
	function<int(int)>bfs=[&](int s)->int{
		queue<int>q;
		for(int i=1;i<=n;i++)d[i]=inf;
		d[s]=0;
		q.push(s);
		while(q.size()){
			int x=q.front();q.pop();
			for(int y:e[x]){
				if(d[x]+1<d[y]){
					d[y]=d[x]+1;q.push(y);
				}
			}
		}
		int t=s;
		for(int i=1;i<=n;i++)if(d[i]>d[t])t=i;
		return t;
	};
	int s=bfs(1);
	int t=bfs(s);
	while(1){
		p[++m]=t;
		if(t==s)break;
		for(int x:e[t]){
			if(d[x]==d[t]-1){
				t=x;break;
			}
		}
	}
}
int dist;//表示现在想知道答案是否可以<=dist 
bool v[N];
int h[N],a[N];
void dfs(int x,int fa){
	a[x]=h[x]=0;
	for(int y:e[x]){
		if(v[y]||y==fa)continue;
		dfs(y,x);
		a[x]+=a[y];
		h[x]=max(h[x],h[y]+1);
	}
	if(!v[x])a[x]+=(h[x]>=dist);
}
int fl[N],fr[N];
int gl[N],gr[N];
bool check(){
	for(int i=1;i<=m;i++)dfs(p[i],0);
	gl[1]=h[p[1]]-1;
	gr[m]=m+h[p[m]];
	fl[1]=a[p[1]]+1;
	fr[m]=a[p[m]]+1;
	for(int i=2;i<=m;i++){
		gl[i]=max(gl[i-1],h[p[i]]-i);
		if(i+gl[i]<=dist)fl[i]=a[p[i]]+1;
		else fl[i]=fl[i-1]+a[p[i]]+1;
	}
	for(int i=m-1;i>=1;i--){
		gr[i]=max(gr[i+1],h[p[i]]+i);
		if(gr[i]-i<=dist)fr[i]=a[p[i]]+1;
		else fr[i]=fr[i+1]+a[p[i]]+1;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(fl[i]+fr[j]>k)continue;
			bool OK=1;
			for(int k=i+1;k<=j-1;k++){
				if(h[p[k]]+min(k-i,j-k)>dist){
					OK=0;break;
				}
			}
			if(OK)return 1;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(fl[i]>k)continue;
		if(gr[i]-i<=dist)return 1;
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int kkksc03,T;cin>>kkksc03>>T;
	while(T--){
		for(int i=1;i<=n;i++)e[i].clear();m=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u]+=v;e[v]+=u;
		}
		if(k==n){
			cout<<0<<"\n";
			continue;
		}
		find_p();
		for(int i=1;i<=n;i++)v[i]=0;
		for(int i=1;i<=m;i++){
			v[p[i]]=1;
		}
		dist=0;
		for(int i=1<<20;i;i>>=1){
			if(dist+i<=n){
				dist+=i;if(check())dist-=i;
			}
		}
		dist++;
		cout<<dist<<"\n";
	}
	return 0;
}
/*
0 1
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


重要结论：两个联通块至少有一个在直径上，如果A不在直径上，A一定在B的子树内而不是其他不被B包含的子树

假设只选择一个联通块，这个联通块必须放在直径上 

重新确定的结论：两个都在直径上 
*/
