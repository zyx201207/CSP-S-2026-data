#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005];
long long min(long long x,long long y){
	if(x < y){
		return x;
	}
	return y;
}
bool check(long long x){
	deque<long long >q;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for(long long i = 1; i <= n; i++){
		while(!q.empty() && q.front() <= i - x){
			q.pop_front();
		}
		while(!q.empty() && a[i] >= a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(i < x)continue;
		if(a[q.front()] * x - (pre[i] - pre[i - x]) <= m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)cin >> a[i];
	for(long long i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i];
	long long ll = 2,rr = n,ans = 0;
	while(ll <= rr){
		long long mid = (ll + rr) / 2;
		if(check(mid)){
			ans = mid;
			ll = mid + 1;
		}else{
			rr = mid - 1;
		}
	}
	cout << ans;
	return 0;
}