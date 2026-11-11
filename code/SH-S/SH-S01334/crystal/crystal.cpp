#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , m;
int a[500010];
int ans;
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	sort(a + 1 , a + 1 + n);
	int last = m;
	int ans = 1;
	priority_queue<int , vector<int> , greater<int>> q;
	q.push(a[1]);
	for(int i = 2 ; i <= n ; i++){
		last -= q.size() * (a[i] - a[i - 1]);
		while(q.size() && last < 0){
			last += a[i] - q.top();
			q.pop();
		}
		q.push(a[i]);
		int x = q.size();
		ans = max(ans , x);
	}
	cout << ans;
	return 0;
}
