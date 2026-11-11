#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5 + 10;
int a[N];
int dd[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	bool flagA = 1,flagB = 1;
	int d = 0;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(a[i]!=i) flagA = 0;
		if(i == 2){
			d = a[i]-a[i-1];
		}
	}
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1] != d) flagB = 0;
	}
	sort(a+1,a+n+1);
	if(flagA){
		for(int i=1;i<=n;++i){
			dd[i]=dd[i-1]+a[i];
		}
		int op = upper_bound(dd+1,dd+n+1,m)-dd;
		cout << op;
		return 0;
	}
	if(flagB){
		int kk = a[n]-a[n-1];
		cout << (m/kk);
		return 0;
	}
	int ans = 0;
	for(int i=1;i<=n;++i){
	    int sum = 0;
	    int tot = 0;
		for(int j=1;j<=i;++j){
			sum+=(a[i]-a[j]);
			if(sum > m) continue;
			tot++;
		
		}
		ans=max(ans,tot);
	}
	cout << ans;
	
	return 0;
}
