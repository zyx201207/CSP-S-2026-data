#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long n,m,a[N],ans=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==1) {
		cout<<1;
		return 0;
	}
	for(long long i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=2; i<=n; i++) {
		long long cnt=m,ans1=1;
		for(long long j=i-1; j>=1; j--) {
			cnt=cnt-a[i]+a[j];
			if(cnt>=0)
				ans1++;
			ans=max(ans,ans1);
		}
	}
	cout<<ans;
	return 0;
}
