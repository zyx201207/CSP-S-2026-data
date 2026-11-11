#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long 
int a[N],sum[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	int l=1,r=1;
	while(r<=n){//O(2N)
		//优化如何快速求出所有的差？ 
		int sum1=(r-l+1)*a[r]-sum[r]+sum[l-1];
		//有极端情况会错 
		//N*a[i]=5e5*1e12=5e17不会爆longlong 
		if(sum1<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
