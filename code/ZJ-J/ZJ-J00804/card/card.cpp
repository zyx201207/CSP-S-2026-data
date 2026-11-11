#include<bits/stdc++.h>

using namespace std;

#define rp(i,j,k) for(int i=(j);i<=(k);i++)
#define pr(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
void gmin(int &x,int y){x=min(x,y);}
void gmax(int &x,int y){x=max(x,y);}


namespace SOLVE{

const int N=5e5+5;
int n,m,a[N],nxt[N],ans[N];
vi e[N];int f[N],siz[N];

void dfs(int u,int fa){
	siz[u]=1;
	for(int v:e[u]){
		if(v==fa)
			continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	if(f[u])ans[f[u]]=siz[u];
	return;
}

void solve(){
	cin>>n>>m;
	rp(i,1,n)
		cin>>a[i];
	nxt[a[n]]=n;
	f[n]=a[n];
	pr(i,n-1,1){
		int x=a[i];
		if(!nxt[x])e[i+1].eb(i),f[i]=x;
		else e[nxt[x]].eb(i);
		nxt[x]=i;
	}
	dfs(n,0);
	rp(i,1,m)
		cout<<ans[i]<<" ";
	return;
}

}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _=1;//cin>>_;
	while(_--)SOLVE::solve();
	return 0;
}
