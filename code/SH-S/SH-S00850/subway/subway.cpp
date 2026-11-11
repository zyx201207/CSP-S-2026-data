#include<bits/stdc++.hj>
using namespace std;
const int N = 1e6+10;
int a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	while(q--){
		for(int i=1;i<=m;i++) cin >> a[i];
		int k;cin >> k;
		int t;
		cin >> t;
		cout << k*t;
	}
	return 0;
}
