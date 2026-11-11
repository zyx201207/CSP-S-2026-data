#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m,ans;

void dfs(int num,int pos,int now){
	if(m-num>n-pos+1) return;
	if(pos==n+1&&num==m){
		ans=max(ans,now);
		return;
	}
	if(num==n){
		ans=max(ans,now);
		return;
	}
	if(a[pos]<=ans) return;
	dfs(num+1,pos+1,ans&a[pos]);
	dfs(num,pos+1,a[pos]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
