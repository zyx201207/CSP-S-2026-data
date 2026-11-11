#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s,a;
	cin >> n >> m;
	int a(100005)
	int s(100005) = (s);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	while (m--){
		int l,r;
		cin >> l >> r;
		cout << s[r] - s[l-1] << endl;
	}
	return;
}
