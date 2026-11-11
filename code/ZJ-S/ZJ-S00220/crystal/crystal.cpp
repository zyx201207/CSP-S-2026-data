#include <bits/stdc++.h>
#define int long long
#define qjq nb666
using namespace std;
int a[500005],f[500005];
int sum(int x,int y){
	if(x>y)return 0;
	return f[y]-f[x-1];
}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,md;
		while(l<=r){
			md=(l+r)>>1;
			if((a[i]*(i-md)-sum(md,i-1))<=m)r=md-1;
			else l=md+1;
		}ans=max(ans,i-l+1);
		//cout<<i-l+1<<"\n";
	}cout<<ans;
	return 0;
}