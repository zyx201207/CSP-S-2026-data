#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],ans;
void dfs(int x,int s,int cnt){
	if(x>n){
		if(cnt==m) ans=max(ans,s);
		return;
	}
	dfs(x+1,s,cnt);
	if(!cnt) dfs(x+1,a[x],cnt+1);
	else dfs(x+1,s&a[x],cnt+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==n){
		ans=a[n];
		for(int i=n-1;i>=1;i--) ans&=a[i];
	}
	else if(m==1) ans=a[n];
	else dfs(1,0,0);
	cout<<ans;
	return 0;
}
