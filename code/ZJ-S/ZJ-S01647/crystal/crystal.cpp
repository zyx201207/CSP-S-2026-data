#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5E5+3;
int a[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,an=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=n; i>=2; i--) {
		int ans=0,h=1;
		for(int j=i-1; j>=1; j--) {
			ans+=a[i]-a[j];
			if(ans>m) break;
			h++;
		}
		an=max(an,h);
	}
	cout<<an;
	return 0;
}
