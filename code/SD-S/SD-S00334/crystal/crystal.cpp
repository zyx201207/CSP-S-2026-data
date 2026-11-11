#include<bits/stdc++.h>
using namespace std;
int a[500005],num[500005],sum[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000) {
		int ans=1;
		for(int i=2; i<=n; i++) {
			int tmp=1,sum=0;
			for(int j=i-1; j>=1; j--) {
				sum+=a[j];
				if(a[i]*tmp-sum<=m)tmp++;
				else break;
			}
			ans=max(ans,tmp);
		}
		cout<<ans;
	} else {
		for(int i=1; i<=n; i++) {
			num[i]=(a[i]-a[i-1])*(i-1);
		}
		for(int i=1; i<=n; i++) {
			sum[i]=sum[i-1]+num[i];
		}
		int k=upper_bound(sum+1,sum+n+1,m)-sum-1;
		cout<<k;
	}
	return 0;
}
