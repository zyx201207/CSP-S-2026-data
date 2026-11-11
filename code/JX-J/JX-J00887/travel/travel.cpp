#include <bits/stdc++.h>

using namespace std;

bool check(string a,string b){
	char x = a[2],y = b[2];
	return ((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C'))
	 || ((x == 'D' || x == 'F') && (y == 'D' || y == 'F'));
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string a,b,c,d;
	cin >> a >> b >> c >> d;

	
	bool fa = false,fb = false,fc = false,fd = false;
	
	if(a == c){
		fa = true;
	}
	if(fa && b[0] == d[0] && b[1] == d[1]){
		fb = true;
	}
	if(fb && check(b,d)){
		fc = true;
	}
	if(fc && abs(b[2]-d[2]) == 1){
		fd = true;
	}
	cout << fa << fb << fc << fd;
	return 0;
}
