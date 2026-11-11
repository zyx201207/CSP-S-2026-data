#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x,y;
string s,t;
char a[4],b[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x >> s >> y >> t;
	s = " " + s;
	t = " " + t;
	if(x == y)
		cout << 1;
	else
		cout << 0;
	if(x == y && s[1] + s[2] == t[1] + t[2])
		cout << 1;
	else
		cout << 0;
	int ok1,ok2;
	a[1] = 'A';
	a[2] = 'B';
	a[3] = 'C';
	b[1] = 'D';
	b[2] = 'F';
	for(int i = 1;i <= 3;i++){
		if(s[3] == a[i])
			ok1 = 1;
		if(t[3] == a[i])
			ok2 = 1;
	}
	for(int i = 1;i <= 2;i++){
		if(s[3] == b[i])
			ok1 = 2;
		if(t[3] == b[i])
			ok2 = 2;
	}
	if(x == y && s[1] + s[2] == t[1] + t[2] && ok1 == ok2)
		cout << 1;
	else
		cout << 0;
	if(x == y && s[1] + s[2] == t[1] + t[2] && ok1 == ok2 && (((s[3] - 'A' + 1 + 'A') == t[3]) || ((s[3] == 'D' && t[3] == 'F') || (s[3] == 'F' && t[3] == 'D'))))
		cout << 1;
	else
		cout << 0;
	return 0;
}