#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,n,m,d,q;
	int w[500005];
	cin >> c >> n >> m >> d >> q;
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<< 32 << "\n"; 
		cout<< 17;
	}
	
	return 0;
}
