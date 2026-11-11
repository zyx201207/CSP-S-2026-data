#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
long long n,m,a[N],qian[N];
bool check(long long t){
	for(int i=1;i<=n-t+1;i++){
		long long r=i+t-1;
		long long sum=a[r]*t-qian[r]+qian[i-1];
		if(sum<=m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qian[i]=qian[i-1]+a[i];
	long long ans=1,l=1,r=n;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
5 5 
1 2 4 8 9
*/