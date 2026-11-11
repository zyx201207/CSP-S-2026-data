#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,m;
int maxx=-1;
int a[N];
void dfs(int u,int x,int cnt){
	if(cnt==m){
		maxx=max(maxx,x);
		return;
	}if(x<=maxx)return;
	if(u>n+1)return;
	dfs(u+1,x,cnt);
	dfs(u+1,x&a[u],cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];dfs(1,a[i],0);
	}
	cout<<maxx;
	return 0;
}

