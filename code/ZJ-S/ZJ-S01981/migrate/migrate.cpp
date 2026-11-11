#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000006];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<n;i++){
		auto it=upper_bound(a+i+1,a+n+1,a[i]+d)-a;
		it--;
		while(it==i+1&&it!=n){
			it=upper_bound(a+it+1,a+n+1,a[it]+d)-a;
			it--;
		}
		if(it-i==2)ans++;
		it=upper_bound(a+it+1,a+n+1,a[it]+d)-a;
		while(it==i+1){
			it=upper_bound(a+it+1,a+n+1,a[it]+d)-a;
			ans++;
		}
	}
	cout<<abs(ans-1);
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}