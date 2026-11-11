#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005],c[500005];
map<int,int>cnt;
bool check(int x){
	int sum = 0,cnt = 0,i,tot;
	for(i = n - 1,tot = 1; tot < x; i --,tot ++){
		cnt += c[i];
		sum += cnt;
	}
	if(sum <= m)return 1;
	for(; i >= 1; i --){
		int r = i + x - 1;
		sum -= c[r] * (x - 1);
		cnt -= c[r];
		cnt += c[i];
		sum += cnt;
		if(sum <= m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i ++){
		cin>>a[i];
		cnt[a[i]] ++;
		ans = max(ans,cnt[a[i]]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1; i < n; i ++){
		c[i] = a[i + 1] - a[i];
	}
	int l = 1,r = n;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid))l = mid;
		else r = mid - 1;
	}
	cout<<l;
	return 0;
}
