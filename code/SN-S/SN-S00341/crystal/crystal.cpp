// 袁梓焜 西安交通大学附属中学 SN-S00341
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,l=1,tmp=0;
	for(int i=1;i<=n;i++){
		tmp+=(i-l)*(a[i]-a[i-1]);
		while(tmp>m) tmp-=a[i]-a[l++];
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
