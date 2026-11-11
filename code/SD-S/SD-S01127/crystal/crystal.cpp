#include<bits/stdc++.h>
#define int long long
using namespace std;
//祈祷明天对你来说，也是美好的一天 
int n,m,a[500005],pre[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;pre[0]=0;
	//a[r]*(r-l+1)-sum
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int l=1,r=1;l<=n;l++){
		while(r<n&&a[r+1]*(r+1-l+1)-(pre[r+1]-pre[l-1])<=m) r++;
		ans=max(ans,r-l+1);
	}cout<<ans<<"\n";
}
