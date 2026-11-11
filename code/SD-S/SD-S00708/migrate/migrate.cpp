#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+20;
int c,t;
int n,d;
int x[N];
bool vis[N];
int idx;
int nxt[N];
int w[N];
int dis[N];
int ans;
int Max;
int pp;
void dfs(int L,int R,int xx,int s){
//	cout<<xx<<"\n";
	if(xx==R){
		if(Max==s) {
			pp++;
		}
		if(Max>s) pp=1,Max=s;
		return ;
	}
	
	for(int i=xx+1;i<=R;i++){
		if(x[i]-x[xx]<=d&&dis[i]>s+1) dfs(L,R,i,s+1);
	}
}
void sol(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];

	for(int l=1;l<n;l++){
		
		for(int r=1;r<=n;r++){
			for(int i=1;i<=n;i++) dis[i]=1e18;
			
			Max=1e18;
			pp=0;
			dfs(l,r,l,0);
			if(pp==2) ans++;
		}
		
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--) sol();
} 
/*
0 1
5 3
-3 0 2 3 4
*/
