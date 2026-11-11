#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int N = 5e5+5;

int n;
ll a[N],m,sum[N];
deque<ll> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i =1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i-1]+ a[i];
	}
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i-1]+ a[i];
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		int l = 1,r = i;
		while(l<r){
			int mid = (l+r)>>1;
			if((i-mid+1)*a[i] - sum[i] + sum[mid-1]>m)l = mid+1;
			else r = mid;
		}
		ans = max(ans,i - l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3-1 2 2 7

*/