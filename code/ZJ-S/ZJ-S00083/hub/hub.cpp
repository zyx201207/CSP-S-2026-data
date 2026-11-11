#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,rt,k,top,fa[1000005],dep[1000005],st[1000005],f[1000005];
vector<int> e[1000005];
bool mark[1000005];
priority_queue<int,vector<int>,greater<int>> q1,q2;
void dfs(int p,int f){
	fa[p]=f;
	dep[p]=dep[f]+1;
	if(dep[p]>dep[rt])rt=p;
	for(int v:e[p])if(v!=f)dfs(v,p);
}
void dfs2(int p,int fa,int val,int op){
	f[p]=0;
	for(int v:e[p])if(v!=fa&&!mark[v]){
		dfs2(v,p,val,op);
		f[p]=max(f[p],f[v]+1);
	}
	if(!op)q1.push(f[p]+val);
	else q2.push(f[p]-val);
}
signed main(){
//	system("fc hub3.ans hub.out");return 0;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear(),mark[i]=0;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		rt=0,dfs(1,0);
		int x=rt;
		rt=0,dfs(x,0);
		top=0;
		while(rt)mark[rt]=1,st[++top]=rt,rt=fa[rt];
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		for(int i=1;i<=top/2;i++)dfs2(st[i],0,i,0);
		for(int i=top/2+1;i<=top;i++)dfs2(st[i],0,i,1);
		for(int i=1;i<=(top+1)/2;i++){
			int sum=1+(i!=top-i+1);
			while(!q1.empty()&&q1.top()-i<=i-1)q1.pop();
			while(!q2.empty()&&q2.top()+(top-i+1)<=i-1)q2.pop();
			if(sum+q1.size()+q2.size()<=k){
				cout<<i-1<<'\n';
				break;
			}
			sum=(top-i+1)-i+1;
			
		}
	}
	return 0;
}