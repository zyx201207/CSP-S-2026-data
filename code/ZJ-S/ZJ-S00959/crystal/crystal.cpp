#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans=1,now;
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int L=1,R=2;R<=n;R++){
		now+=(a[R]-a[R-1])*(R-L); // R-L=last length
		while(L<=R&&now>m){
			now-=(a[R]-a[L]);
			L++;
		}
		ans=max(ans,R-L+1);
	}
	cout<<ans;
	return 0;
}
