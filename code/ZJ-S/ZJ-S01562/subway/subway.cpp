#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a;
	int t;
};
struct node2{
	int l,r;
}qu[100010];
vector<node> A[510];
int w[500010];
bool check(int n){
	for(int i=1;i<=n;i++){
		int ss=A[i].size();
		for(int j=1;j<ss;j++){
			//cout<<A[i][j-1].t<<" "<<A[i][j].t<<"\n";
			if(A[i][j-1].t!=A[i][j].t)return 0;
		}
		//cout<<"\n";
	}
	return 1;
}
vector<int> G[510];
bool vis[510];
int pfans=LONG_LONG_MAX;
void dfs(int now,int nans,int fin,int t){
	if(now==fin){
		pfans=min(pfans,nans);
		return;
	}
	int ss=G[now].size();
	for(int i=0;i<ss;i++){
		//cout<<G[now][i]<<" ";
		if(vis[G[now][i]]==1)continue;
		vis[G[now][i]]=1;
		dfs(G[now][i],nans+t,fin,t);
		vis[G[now][i]]=0;
	}
	//cout<<"\n";
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			A[i].push_back({x,y});
			G[x].push_back(A[i][j-1].a);
			G[A[i][j-1].a].push_back(x);
		}
	}
	for(int i=1;i<=q;i++)cin>>qu[i].l>>qu[i].r;
	if(check(n)){
		int kkk=A[1][1].t;
		for(int i=1;i<=q;i++){
			int st=qu[i].l;
			int fi=qu[i].r;
			dfs(st,0,fi,kkk);
			pfans+=w[st]+w[fi];
			cout<<w[st]+w[fi]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int st=qu[i].l;
		int fi=qu[i].r;
		cout<<w[st]+w[fi]<<"\n";
	}
	return 0;
}/*
0 3 3 2 1
0 0 0
2 1 1 2 1
2 2 1 3 1
2 1 1 3 1
1 2
*/
