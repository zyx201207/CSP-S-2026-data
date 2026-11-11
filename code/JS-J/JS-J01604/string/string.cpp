#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];
char c[N];

using ll = long long;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n; cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int l = 1,r = n,lnum = a[1],rnum = a[n];
	ll res = 0;
	while(l < r){
		//~ cout << l << " " << r << " " << lnum << " " << rnum << "\n";
		int tmp = min(lnum,rnum);
		if(c[l] != c[r]) res += tmp;
		lnum -= tmp;
		rnum -= tmp;
		if(!lnum) lnum = a[++l];
		if(!rnum) rnum = a[--r];
	}
	cout << res << "\n";
	return 0;
}
