#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, m;
ll k = 0;
ll ans = 0;
ll T;

string a ="";
string s;
string s1;

int main (){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	
	cin >> n ;
	
	for (int i = 1;i <= n;i ++){
		cin >> T;
		cin >> s;
		k += T;
		for (int j = 1;j <= T;j ++){
			a += s;
		}
	}
	for (int i = 1, j = k;i < j; i ++, j --){
		
		if (a[i] != a[j]){
			ans ++;
		}
	}
	
	 cout << ans <<endl;
	return 0;
}
