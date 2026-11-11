#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
/*====================*/
string c1,c2,s1,s2;
/*====================*/
void solve(void){
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1==c2 ? 1 : 0);
	cout << (c1==c2 && s1.substr(0,2)==s2.substr(0,2) ? 1 : 0);
	cout << (c1==c2 && s1.substr(0,2)==s2.substr(0,2) && (((s1[2]<='C')==(s2[2]<='C'))) ? 1 : 0);
	cout << (c1==c2 && s1.substr(0,2)==s2.substr(0,2) && (((s1[2]<='C')==(s2[2]<='C'))) && (abs(s1[2]-s2[2])<=1) ? 1 : 0);
}
/*====================*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
	return 0;
}
