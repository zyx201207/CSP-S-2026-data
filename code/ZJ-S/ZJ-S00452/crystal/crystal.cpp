#include <bits/stdc++.h>
using namespace std;
#define int long long
#define CK cerr<<"\n"<<1.0*fabs(&ED-&ST)/1024/1024<<"MB\n";
bool ST;
const int N=500010;
int n,m,a[N],ans,la;
bool ED;
signed main(){
//	freopen("crystal1.in","r",stdin);
//	freopen("crystal.out","w",stdout);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	la=n;
	for(int i=n;i>=1;--i){
		while(la>=1&&a[i]-a[la]<=m){
			m-=a[i]-a[la];
			--la;
		}
		ans=max(ans,i-la);
		m+=(i-la-1)*(a[i]-a[i-1]);
	}
	cout<<ans;
//	CK
	return 0;
}
/*
5 5
1 2 4 8 9
*/
