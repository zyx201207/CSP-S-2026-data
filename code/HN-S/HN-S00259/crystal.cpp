#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

namespace solution{
	int n,m;
	int a[500005];
	int s[500005];
	void main(){
		cin>>n>>m;
		for(int i = 1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i = 1;i<=n;i++) s[i] = s[i-1]+a[i];
		int ans = 0;
		for(int i = 1;i<=n;i++){
			int l = 1,r = i-1;
			int nowans = i;
			while(l<=r){
				int mid = (l+r)>>1;
				if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m){
					nowans = mid;
					r = mid-1;
				}else l = mid+1;
			}
			ans = max(ans,i-nowans+1);
		}
		cout<<ans;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}

