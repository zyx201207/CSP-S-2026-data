#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m;
int a[N];
int sum=LLONG_MIN/2;
bool vis[N];
void deal(){
	int ans=0,k=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(k==0) ans=a[i],k=1;
			else ans&=a[i];
		}
	}
	sum=max(sum,ans);
	return ;
}
void dfs(int s,int g){
	if(g>m){
		deal();
		return ;
	}
	if(s>n) return ;
	vis[s]=true;
	dfs(s+1,g+1);
	vis[s]=false;
	dfs(s+1,g);
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1);
	cout<<sum;
	return 0;
}
