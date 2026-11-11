#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 5e5 + 5;

int n, m;
int a[N];

int cnt[N];

int ans[N];
int res[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n){
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	int sum = 0;
	rep(i, 1, n){
		res[i] += i - sum;
		ans[a[i]] += res[i];
		sum += res[i];
		cnt[a[i]]--;
		if(!cnt[a[i]]){
			sum -= ans[a[i]];
		}
	}
	
	rep(i, 1, m){
		cout << ans[i];
		if(i == m) cout << '\n';
		else cout << ' ';
	}
	
	return 0;
}