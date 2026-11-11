#include<bits/stdc++.h>
#define int long long
using namespace std;

int m,n,ans,a[500005];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int x=m,cnt=1,j=i;
		while(j--){
			x-=a[i]-a[j];
			if(x<0) break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}