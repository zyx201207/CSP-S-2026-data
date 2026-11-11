#include <bits/stdc++.h>
using namespace std;
const int N = 5e2+5,M = 5e5+5;
int a[M],t[M][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;cin >> C >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	int ai;cin >> ai;
	for(int i = 0;i < ai;i++){
		int j,k;cin >> j >> k;
		t[j][0] = k;
	}
	cin >> ai;int minn = 2147483647;
	for(int i = 0;i < ai;i++){
		int j,k;cin >> j >> k;
		if(t[j][0] != 0) minn = min(minn,t[j][0]+k);
		t[j][1] = k;
	}
	while(q--){
		int l,r;cin >> l >> r;
		if(t[l][0]&&t[r][0]&&t[l][1]&&t[r][1]) cout << min(t[l][0]+t[r][0],t[l][1]+t[r][1])+a[l]+a[r];
		else if(t[l][0] && t[r][0]) cout << t[l][0]+t[r][0]+a[l]+a[r];
		else if(t[l][1] && t[r][1]) cout << t[l][1]+t[r][1]+a[l]+a[r];
		else if(t[l][0] && t[r][1]) cout << t[l][0]+t[r][1]+minn+a[l]+a[r];
		else if(t[l][1] && t[r][1]) cout << t[l][1]+t[r][0]+minn+a[l]+a[r];
		else cout << "I will get IOI Au! I will AK IOI!";
		cout << '\n';
	}
	return 0;
}