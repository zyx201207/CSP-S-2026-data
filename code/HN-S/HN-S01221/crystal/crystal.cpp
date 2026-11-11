#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	int r=0,ans=0;
	for(int l=1;l<n;l++){
		r=max(r,l);
		while(r+1<=n&&m>=a[l]-a[r+1]){
			m-=a[l]-a[r+1];
			++r;
		}
		ans=max(ans,r-l+1);
		m+=(a[l]-a[l+1])*(r-l+1);
	}
	cout<<ans;
	return 0;
}
