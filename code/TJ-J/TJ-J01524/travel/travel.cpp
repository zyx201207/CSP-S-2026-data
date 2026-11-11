#include <bits/stdc++.h>
using namespace std;

struct piao{
	string c;
	string s;
};

piao a[7];
bool p[9];

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a[1].c >> a[1].s >> a[2].c >> a[2].s;
    if (a[1].c == a[2].c){
    	p[1] = 1;
	}
	if (p[1] && a[1].s[0] == a[2].s[0] && a[1].s[1] == a[2].s[1]){
		p[2] = 1;
	} 
	if (p[2] && ((a[1].s[2] >= 'A' && a[1].s[2] <= 'C' && a[2].s[2] >= 'A' && a[2].s[2] <= 'C') || (a[1].s[2] >= 'D' && a[1].s[2] <= 'F' && a[2].s[2] >= 'D' && a[2].s[2] <= 'F'))){
		p[3] = 1;
	}
	int b = abs(a[1].s[2] - a[2].s[2]);
	if (p[3] && (b == 1 || a[1].s[2] == 'D' || a[1].s[2] == 'F')){
		p[4] = 1;
	}
	cout << p[1] << p[2] << p[3] << p[4];
	return 0;
}
