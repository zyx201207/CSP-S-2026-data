#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,k;
vector<int>e[1000010];
int ans=0;
int r[1000010];
int vis[1000010];
void ddd(int x,int fa){
//	cout<<x<<" "<<fa<<endl;
	if(!r[x])return;
	vis[x]=1;
	for(int v:e[x])if(v!=fa)ddd(v,x);
}
int getdis(int x,int fa){
	if(r[x])return 0;
	int res=1e18;
	for(int v:e[x]){
		if(v==fa)continue;
		res=min(res,getdis(v,x)+1);
	}
	return res;
}
void dfs(int x,int u){
	if(u>k)return;
	if(n-x+1<k-u)return;
	if(x==n+1){
		for(int i=1;i<=n;i++)vis[i]=0;
		int hv=0;
		for(int i=1;i<=n;i++){
			if(!r[i])continue;
			if(!vis[i])hv++,ddd(i,0);
		}
		if(hv>2||!hv)return;
		int res=0;
		for(int i=1;i<=n;i++){
			if(!r[i])res=max(res,getdis(i,0));
		}
		ans=min(ans,res);
		return;
	}
	dfs(x+1,u);
	r[x]=1;
	dfs(x+1,u+1);
	r[x]=0;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(C==13||C==14){
		int m=n/2;
		if(n==k){
			cout<<0<<endl;
			return;
		}
		int a=k/2,b=k-a;
		int l=m-k;
		if(l<=0){
			cout<<1<<endl;
			return;
		}
		cout<<(l+3)/4+1<<endl;
		return;
	}
	ans=1e18;
	dfs(1,0);
	cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    freopen("hub5.in","r",stdin);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
    	solve();
	}
	
    return 0;
}
/*
先写暴力 

0 2
5 2
1 2
2 3
3 4
4 5
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


不对啊，这道题大样例都只有 13,14，是不是防 AK 题 


对于特殊性质 A 
我们发现最优就是分成两段 
 
13 1
9 3
1 2
2 3
3 4
4 5
1 6
2 7
3 8
7 9

13 1
11 2
1 2
2 3
3 4
4 5
5 6
1 7
2 8
3 9
4 10
5 11


13 1
13 2
1 2
2 3
3 4
4 5
5 6
6 7
1 8
2 9
3 10
4 11
5 12
6 13




*/