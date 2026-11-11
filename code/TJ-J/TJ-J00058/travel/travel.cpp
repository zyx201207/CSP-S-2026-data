#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool a_1=0,b_1=0,c_1=0,d_1=0;
char a_2,b_2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	//cout << a << b << c << d;
	a_1 = (a == c);
	a_2 = b[2];
	b_2 = d[2];
	if(a_1){
		b_1 = (b.substr(0,2) == d.substr(0,2));
		if(b_1){
			c_1 = (a_2 > 'C' == b_2 > 'C');
			if(c_1){
				d_1 = (abs(a_2-b_2) == 1);
			}
		}
	}
	cout << a_1 << b_1 << c_1 << d_1;
	return 0;
}
