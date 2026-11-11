#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a1,b1,a2,b2,c1,c2;
ll d1,d2;
bool a,b,c,d;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> a1 >> b1 >> a2 >> b2;
	
	c1 = b1.substr(0,2),c2 = b2.substr(0,2);
	d1 = b1[2]-'A', d2 = b2[2]-'A';
	

	a = a1 == a2;
	b = c1 == c2 && a;
	c = ((d1 <= 2 && d2 <= 2) || (d1 >= 3 && d2 >= 3)) && b;
	d = abs(d1-d2) == 1 && c;
	cout << a << b << c << d << "\n";
	
	return 0;
}

