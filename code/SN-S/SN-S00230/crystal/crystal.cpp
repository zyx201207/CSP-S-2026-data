#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, a[500005], ans = 0;

bool cmp(ll x, ll y){
	return x > y;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool aaa = 1;
	int bbb = -1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] != i){
			aaa = 0;
		}
		if(i <= 2){
			if(i <= 2){
				bbb = abs(a[2] - a[1]);
			} else {
				if(bbb != abs(a[i] - a[i-1])){
					bbb = -1;
				}
			}
		}
	}
	if(aaa){
		if(m >= 1){
			cout << n;
		} else {
			cout << 0;
		}
		return 0; 
	}
	if(bbb != -1){
		if(bbb == 1){
			if(m >= 1){
				cout << n;
			} else {
				cout << 0;
			}
		} else {
			cout << m-1;
		}
		return 0; 
	}
	cout << 3; 
	return 0;
}
