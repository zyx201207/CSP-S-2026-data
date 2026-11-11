#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read(){
	TN rst=0;bool mns=0;
	char ch=getchar();
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')mns=1,ch=getchar();
	while(isdigit(ch))rst=rst*10+(ch^48),ch=getchar();
	return mns?-rst:rst;
} 
int n,m,nC,chs[1000005],id[1000005],nT,vst[1000005],fa[1000005],ans;
vector<int> to[1000005];
inline int find(int u){
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
inline bool check(){
	int cnt=0;
	for(int i=1;i<=m;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
		for(int &j:to[chs[i]])
			if(id[j])
				fa[find(i)]=find(id[j]);
	for(int i=1;i<=m;++i)
		if(find(i)==i&&++cnt>2)
			return 0;
	return 1;
}
inline void upd(){
	int rst=0;
	queue<int> q;
	++nT;
	for(int i=1;i<=nC;++i){
		q.push(chs[i]);
		vst[chs[i]]=nT;
	}
	q.push(0);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(!u){
			if(q.front()){
				++rst;
				q.push(0);
				continue;
			}
			break;
		}
		for(int &v:to[u])
			if(vst[v]!=nT){
				vst[v]=nT;
				q.push(v);
			}
	}
	ans=min(ans,rst);
}
inline void dfs(int u){
	if(n-u+nC>=m)dfs(u+1);
	chs[++nC]=u;
	id[u]=nC;
	if(nC==m){
		if(check())upd();
	}else dfs(u+1);
	id[u]=0;
	--nC;
}
inline void main_solve(){
	n=read<int>();
	m=read<int>();
	for(int i=1;i<=n;++i)to[i].clear();
	for(int i=1;i<n;++i){
		int u=read<int>(),v=read<int>();
		to[u].push_back(v);
		to[v].push_back(u);
	}
	ans=n;
	dfs(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	read<int>();
	int nTest=read<int>();
	while(nTest--)main_solve();
	return 0;
}
