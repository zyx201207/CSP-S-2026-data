#include <bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],n,m,mx=-1e9,ans;//O(n log n)
bool check(long long x,long long y){
	return (y-x)*a[y]-s[y-1]+s[x-1]>m;
}
long long find(long long x){
	long long l=0,r=x+1;
	while(l<r-1){
		long long mid=(l+r)>>1;
		if(check(mid,x))l=mid;
		else r=mid;
	}
	return x-l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		ans=find(i);
		//cout << i << ":" << ans << endl;
		mx=max(mx,ans);
	}
	cout << mx << endl;
	return 0;
}
