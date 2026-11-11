#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,t,z,y;
string a;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++){
		char q;
		int o;
		cin >> o >> q;
		t += o;
		for (int j = 0;j < o;j++){
			a += q;
		}
	}
	if (n == 1){
		cout << 0;
		return 0;
	}
	y = t - 1;
	t /= 2;
	for (int i = 0;i < t;i++){
		if (a[i] != a[y - i]){
			z += 1;
		}
	}
	cout << z;
}
