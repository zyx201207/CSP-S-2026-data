#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5000005;
ll energy[MAXN] = {0};
ll chazhi[MAXN] = {0};

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n = 0;
	ll m = 0;
	cin >> n;
	cin >> m;
	ll kebi = 0;
	for (int i = 0; i < n; i++) {
		cin >> energy[i];
	}
	sort(energy, energy + n);
	for (int i = 1; i < n; i++) {
		chazhi[i - 1] = energy[i] - energy[i - 1];
	}
	for(int j = 0;j<n-1;j++){
		kebi += chazhi[j]*(j+1);
	}
	if(kebi <= m){
		cout << n;
	} else {
		for(int i = 0;i<n-1;i++){
			kebi = kebi-(n-i)*chazhi[n-i-1];
			if(kebi <= m){
				cout << n - i;
				break;
			}
		}
	}
	return 0;
}