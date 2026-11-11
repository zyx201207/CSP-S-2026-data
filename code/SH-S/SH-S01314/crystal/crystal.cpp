#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500020];
int sum(int l,int r) {
	int cnt=0;
	for(int i=l;i<r;i++) {
		cnt+=(a[r]-a[i]);
	}
	return cnt;
}
void bfs(int l,int len) {
	if(len<=ans) return ;
	if(sum(l,l+len-1)<=m) {
		ans=len;
		return ;
	}
	if(l+len-1==n) bfs(1,len-1);
	else bfs(l+1,len);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bfs(1,n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
