#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,a[N],ans,r=1,sum[N],m;
bool check(int l){
	int n1=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
	return n1<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int l=1;l<=n;l++){
		while(r<=n&&check(l))r++;
		ans=max(r-l,ans);
	}
	cout<<ans;
	return 0;
}
