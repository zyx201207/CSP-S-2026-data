#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+5;
int n,m;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int l=1,r=1;r<=n;r++){
		while(sum[r]-sum[l-1]+m<(r-l+1)*a[r])l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
