#include<bits/stdc++.h>
using namespace std;
long long read(){
	char ch=getchar();
	long long dat=0,t=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
const long long M=5e5+10;
long long c,n,m,d,q;
long long w[M],k,aij,tij;
long long xr,yr;
struct node{
	long long line,linetime;
};
vector<vector<node>> a;
vector<vector<long long>> b;
bool vis[410],vis2[410][410];
long long dfs(long long now,long long li,long long time){
	if(now==yr){
		return time;
	}
	vis[now]=1;
	//buhuan
	long long ans=1e18;
	if(li!=-1){
		for(long long nxt:b[li]){
			if(vis[nxt] || vis2[nxt][li]) continue;
			ans=min(ans,dfs(nxt,li,time));
		}
	}
	if(li!=-1){
		vis2[now][li]=1;
	}
	//huan
	for(node coic:a[now]){
		long long line=coic.line,t=coic.linetime;
		if(vis2[now][line]) continue;
		vis2[now][line]=1;
		ans=min(ans,time+t+dfs(now,line,t));
	}
	vis[now]=0;
	if(li!=-1)vis2[now][li]=0;
//	cout<<"//////////////////\n";
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(long long i=1;i<=m;i++) w[i]=read();
	a.assign(m+1,vector<node>());
	for(long long i=1;i<=n;i++){
		k=read();
		while(k--){
			aij=read();
			tij=read();
			a[aij].push_back({i,tij});
			b[i].push_back(aij);
		}
	}
	while(q--){
		xr=read(),yr=read();
		if(c>=0){
			memset(vis,0,sizeof(0));
			memset(vis2,0,sizeof(0));
			vis[xr]=1;
			cout<<w[xr]+w[yr]+dfs(xr,-1,0)<<"\n";
		}
	}
	return 0;
}
