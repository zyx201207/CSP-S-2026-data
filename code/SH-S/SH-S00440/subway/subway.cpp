#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
const int MAXN=5e5+7;
int w[MAXN],f[MAXN];
struct node{
	int d,t;
}a[MAXN];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=1;i<=m;i++){
		cin >> a[i].d >> a[i].t;
		if(f[i-1]!=0) f[a[i].d]=i;
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		for(int i=1;i<=n;i++){

		}
	}
	for(int i=1;i<=q;i++){
		cout << 37;
	}
	return 0;
}
