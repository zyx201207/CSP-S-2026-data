#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
long long n,m;
long long a[500005];
long long q[500005];
long long h[500005],ans=0;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=1,sum=0,k=a[1];
	while(l<=n){
		while(r+1<=n&&sum+((r-l+1)*(a[r+1]-k))<=m){
			r++;
			sum+=(r-l)*(a[r]-k);
			k=a[r];
		}
//		cout<<l<<" "<<r;
		ans=max(ans,r-l+1);
		sum-=k-a[l];
		l++;
	}
	cout<<ans;
}
I_don_t_want_to_AFO{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}
