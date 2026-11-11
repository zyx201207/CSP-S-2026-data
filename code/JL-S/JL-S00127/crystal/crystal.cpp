#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n,m;
int a[N];
int pre[N];
int ans;
int l,r;
int mid;

bool cheak(int mid){
	for(int i = mid;i <= n;i++){
		if(a[i] * mid - pre[i] + pre[i - mid] <= m) return 1;
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	l = 1,r = n;
	while(l <= r){
		mid = (l + r) / 2;
		if(cheak(mid)){
			l = mid + 1;
			ans = max(ans,mid);
		}else r = mid - 1;
	}
	cout<<ans;
	return 0;
}
