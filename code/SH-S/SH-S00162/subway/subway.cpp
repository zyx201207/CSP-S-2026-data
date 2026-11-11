#include <bits/stdc++.h>
#define int long long
using namespace std;
int p[2010],n,m,k,d,q,idx,s[1000010],to[2010][2010],t[2010],i,j;
bool in(int x,int y,int l,int r){
	if(x > y) swap(x,y);
	if(l > r) swap(l,r);
	return(x == l && y == r);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	memset(to,0x3f,sizeof(to));
	cin >> idx >> n >> m >> d >> q;
	for(int a = 1;a <= m;a++) cin >> p[a];
	for(int a = 1;a <= m;a++) to[m][m] = 0;
	for(int a = 1;a <= n;a++){
		cin >> k;
		for(int b = 1;b <= k;b++) cin >> s[b] >> t[b];
		for(int b = 1;b <= k;b++) for(int c = 1;c <= k;c++) to[s[b]][s[c]] = max(to[s[b]][s[c]],t[s[b]] + t[s[c]]);
	}
	if(m == 2){
		for(int a = 1;a <= q;a++){
			cin >> i >> j;
			cout << to[1][2] + p[1] + p[2] << endl;
		}
	}
	if(m == 3){
		for(int a = 1;a <= q;a++){
			cin >> i >> j;
			if(in(i,j,1,2)) cout << max(to[1][2],to[1][3] + to[2][3]) + p[1] + p[2] << endl;
			if(in(i,j,1,3)) cout << max(to[1][3],to[1][2] + to[2][3]) + p[1] + p[3] << endl;
			if(in(i,j,2,3)) cout << max(to[2][3],to[1][2] + to[1][3]) + p[2] + p[3] << endl;
		}
	}
	return(0);
}
