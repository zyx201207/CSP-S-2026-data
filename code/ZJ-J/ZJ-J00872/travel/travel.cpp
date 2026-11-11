#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 15;
char c1[N],s1[N],c2[N],s2[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag1 = bool(c1[0] == c2[0] && c1[1] == c2[1]);
	bool flag2 = bool(flag1 && s1[0] == s2[0] && s1[1] == s2[1]);
	bool w1 = bool(s1[2] == 'D' || s1[2] == 'F');
	bool w2 = bool(s2[2] == 'D' || s2[2] == 'F');
	bool flag3 = bool(flag2 && w1 == w2);
	cout << flag1 << flag2 << flag3;
	char x1 = s1[2],x2 = s2[2];
	if(x1 > x2) swap(x1,x2);
	if(flag3){
		if(x1 == 'D' && x2 == 'F') cout << 1 << endl;
		else if(x2-x1 == 1) cout << 1 << endl;
		else cout << 0 << endl;
	} else cout << 0 << endl;
	return 0;
}
