#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n,m,mx;
vector<long long> a,pre;
int check(int l,int r){
	return (r - l) * a[r] - (pre[r - 1] - pre[l - 1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	a.resize(n + 1);
	pre.resize(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a.begin() + 1,a.end(),less<int>());
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + a[i];
	}
	for(int i = 1,j = 1;i <= n;i++){
		while(check(i,j + 1) <= m && j < n){
			j++;
		}
		mx = max(mx,j - i + 1);
	}
	cout << mx;
	return 0;
}