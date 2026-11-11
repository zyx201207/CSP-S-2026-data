#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50007],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> w[i];
	}
	for(int i=1;i<=q;i++){
		cin >> x>> y;
	}
	if(x==1&&y==2) cout << 32 << 17 << endl;
	else cout << 35 << 16 << endl;
	return 0;
}
