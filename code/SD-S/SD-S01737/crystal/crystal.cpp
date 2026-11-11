#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+3;
int n,m,ans,now;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for (int i = 1;i <= n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	int l = 1,r = 0;
	while (r < n){
		r++;
		if (now+(r-l)*(a[r]-a[r-1]) <= m){
			ans = max(ans,r-l+1);
			now += (r-l)*(a[r]-a[r-1]);
		}
		else{
			for (;l < r;l++){
				if (now+(r-l)*(a[r]-a[r-1]) <= m)  break;
				now -= a[r-1]-a[l];
			}
			now += (r-l)*(a[r]-a[r-1]);
			ans = max(ans,r-l+1);
		}
	}
	cout<<ans;
	
	return 0;
}
