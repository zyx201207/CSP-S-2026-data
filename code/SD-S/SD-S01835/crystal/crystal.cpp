#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum;
long long a[500005],dp[500005],dpp[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	for(int i=0; i<n; i++) {
		dp[i]=a[i+1]-a[i];
	}
	int d=dp[0];
	bool flag=0;
	for(int i=0; i<n-1; i++) {
		if(d!=dp[i]) {
			flag=1;
		}
	}
	if(!flag) {
		int i=d;
		while(m>0) {
			ans++;
			m-=i;
			i+=d;
		}
	} else {
		sum/=n;
		for(int i=0; i<n; i++) {	
			dpp[i]=abs(a[i]-sum);
		}
		sort(dpp,dpp+n);
		while(m>0) {
			m-=dpp[ans++];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

