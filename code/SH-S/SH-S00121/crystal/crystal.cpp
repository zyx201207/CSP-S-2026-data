#include <iostream>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int u = 0;
int n,a[maxn],m,ans = 0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout)
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,less<int>());
	queue<int> q;
	a[0] = a[1];
	for(int i = 1;i <= n;i++){
		u += (a[i] - a[i-1]) * q.size();
		q.push(a[i]);
		while(q.size() && u > m){
			int l = q.front();
			q.pop();
			u -= a[i] - l;
		}
		int nn = q.size();
		ans = max(ans,nn);
	}
	cout << ans;
}
