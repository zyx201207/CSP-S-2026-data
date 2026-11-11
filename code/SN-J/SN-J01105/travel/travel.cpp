#include<bits/stdc++.h>
#define lint long long
using namespace std;
int x,y,xx,yy;
char cx,cy;
string s;
bool ok1,ok2,ok;
int main(){
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> x >> s;
	xx = (s[0] - '0') * 10 + s[1] - '0';
	cx = s[2];
	cin >> y >> s;
	yy = (s[0] - '0') * 10 + s[1] - '0';
	cy = s[2];
	if(cx == 'F') cx--;
	if(cy == 'F') cy--;
	if(x == y) ok1 = true;
	cout << (x == y ? 1 : 0);
	if(ok1 && xx == yy) ok2 = true,cout << 1;
	else cout << 0;
	if(ok1 && ok2 && cx <= 'C' && cy <= 'C') cout << 1,ok = true;
	else if(ok1 && ok2 && cx >= 'D' && cy >= 'D') cout << 1,ok = true;
	else cout << 0;
	if(ok1 && ok && ok2 && abs(cx - cy) == 1) cout << 1;
	else cout << 0;
	return 0;
} 
