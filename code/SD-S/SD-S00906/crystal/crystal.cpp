#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,ans;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=0;
	for(int l=1,r=1;r<=n;r++){
		cnt+=a[r];
		while((r-l+1)*a[r]-cnt>m) cnt-=a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
