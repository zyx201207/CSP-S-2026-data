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
int n,m,q,a[500005],nB[500005],b[500005][25],c[500005][25];
long long to[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	read<int>();
	n=read<int>();
	m=read<int>();
	read<int>();
	q=read<int>();
	for(int i=1;i<=m;++i)a[i]=read<int>();
	for(int i=1;i<=n;++i){
		int amt=read<int>();
		while(amt--){
			int p=read<int>(),w=read<int>();
			++nB[p];
			b[p][nB[p]]=i;
			c[p][nB[p]]=w;
		} 
	}
	for(int i=1;i<=n;++i){
		fill(to[i],to[i]+n+1,1145141919810114514ll);
		to[i][i]=0;
	}
	for(int i=1;i<=m;++i)
		for(int j=1,u;j<nB[i];++j){
			u=b[i][j];
			for(int k=j+1,v;k<=nB[i];++k){
				v=b[i][k];
				to[u][v]=min(to[u][v],((long long)c[i][j])+c[i][k]);
			}
		}
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j){
			to[i][j]=min(to[i][j],to[j][i]);
			to[j][i]=to[i][j];
		}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				to[i][j]=min(to[i][j],to[i][k]+to[k][j]);
	while(q--){
		int u=read<int>(),v=read<int>();
		long long ans=1145141919810114514ll;
		for(int i=1;i<=nB[u];++i)
			for(int j=1;j<=nB[v];++j)
				ans=min(ans,c[u][i]+to[b[u][i]][b[v][j]]+c[v][j]);
		cout<<a[u]+ans+a[v]<<'\n';
	}
	return 0;
}
