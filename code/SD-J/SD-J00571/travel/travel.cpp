#include<bits/stdc++.h>
using namespace std;
string a,b;
char c,d,e;
char f,g,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> c >> d >> e >> b >> f >> g >> h;
	if(a == b) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(int(c) == int(f) && int(d) == int(g)) cout << 1;
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if((e == 'B' && h == 'C') || (e == 'C' || h == 'C')){
		cout << 0 << 0; 
		return 0;
	}
	else cout << 1;
	if((int(e) + 1 == h) || (int(e) - 1 == h)) cout << 1;
	else cout << 0;
	return 0;
}
