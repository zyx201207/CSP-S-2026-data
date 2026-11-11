#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n,ans;

pair<int,char> a[N],b[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i].first >> a[i].second;
		b[n-i+1] = a[i];
	}
	int i = 1,j = 1;
	while(i <= n) {
		if(a[i].second == b[j].second) {
			int num = min(a[i].first,b[j].first);
			a[i].first -= num,b[j].first -= num;
			if(a[i].first == 0) i++;
			if(b[j].first == 0) j++;
		}else {
			int num = min(a[i].first,b[j].first);
			ans += num;
			a[i].first -= num,b[j].first -= num;
			if(a[i].first == 0) i++;
			if(b[j].first == 0) j++;
		}
	}
	cout << (ans >> 1);
	return 0;
}
