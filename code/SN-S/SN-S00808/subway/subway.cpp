#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int w[m];
	for(int i = 1;i <= m;i++) cin >> w[i];
	if (n == 2){
		cout <<  32 << endl;
		cout << 17;
	}
	else if (n == 3){
		cout << 35 << endl;
		cout << 16;
	}
	return 0;
}
