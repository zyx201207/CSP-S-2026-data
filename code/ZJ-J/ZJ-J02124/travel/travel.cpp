#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string p1 = "" + s1[0] + s1[1];
	string p2 = "" + s2[0] + s2[1];
	char q1 = s1[2],q2 = s2[2];
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && p1 == p2) cout << 1;
	else cout << 0;
	if(c1 == c2 && p1 == p2 && ((q1 <= 'C' && q2 <= 'C') || (q1 >= 'D' && q2 >= 'D'))) cout << 1;
	else cout << 0;
	if(c1 == c2 && p1 == p2 && ((q1 <= 'C' && q2 <= 'C' && abs((int)q1 - (int)q2) == 1) || (q1 >= 'D' && q2 >= 'D'))) cout << 1;
	else cout << 0;
	return 0;
}
