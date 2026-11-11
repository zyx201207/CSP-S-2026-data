#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],s[200005],maxx,cnt;
void dfs(int x,int w,int s){
	if(x==n){
		if(!w)maxx=max(s,maxx);
		return;
	}
	x++;
	if(w){
		if(s==0)dfs(x,w-1,a[x]);
		else dfs(x,w-1,s&a[x]);
	}
	dfs(x,w,s);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,m,0);
	cout<<maxx;
	return 0;
}