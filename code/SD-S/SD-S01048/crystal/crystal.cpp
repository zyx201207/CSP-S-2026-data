#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,su=0;
	while(r<=n){
		while(su>m){
			su-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
		su+=(r-l)*(a[r]-a[r-1]);
	}
	cout<<ans<<"\n";
	return 0;
}
//-static-libgcc
