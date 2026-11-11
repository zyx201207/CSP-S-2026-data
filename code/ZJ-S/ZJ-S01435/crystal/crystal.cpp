#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long n, m;
long long a[N];
long long su[N];
int ans;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	su[1] = a[1];
	for(int i = 2 ; i <= n ; i++)su[i] = a[i] + su[i - 1];
	for(int i = 1 ; i <= n ; i++){
		int j = i + 1;
		while(su[j] - su[i - 1] + m >= (j - i + 1) * a[j] && j <= n){
			j++;
		}
		ans = max(ans, j - i);
	}
	cout << ans;
	return 0;
}
