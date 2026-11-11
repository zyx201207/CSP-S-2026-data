#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		long long c=0;
		int l=i-1;
		while(c+abs(a[i]-a[l])<=m && l>=1){
			c+=abs(a[i]-a[l]);
			l--;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}


