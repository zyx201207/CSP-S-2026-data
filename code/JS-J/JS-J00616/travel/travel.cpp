#include <iostream>
#include <cmath>
using namespace std;
bool tc(char a,char b) {
    if (a == 'A' && (b == 'B' || b == 'C')) return 1;
    if (a == 'B' && (b == 'A' || b == 'C')) return 1;
    if (a == 'C' && (b == 'A' || b == 'B')) return 1;
    if (a == 'D' && b == 'E') return 1;
    if (a == 'E' && b == 'D') return 1;
    return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	bool f1,f2,f3,f4;
	f1 = f2 = f3 = f4 = 0;
	cin >> r1 >> r2 >> x1 >> x2;
	if (r2[2] == 'F') r2[2] = 'E'; 
	if (x2[2] == 'F') x2[2] = 'E'; 
	if (r1 == x1) {
	    f1 = 1;
	    if (r2[0] == x2[0] && r2[1] == x2[1]) {
	    	f2 = 1;
		if (tc(r2[2],x2[2])) {
		    f3 = 1;
		    if (abs(r2[2] - x2[2]) == 1) f4 = 1;
		}
	    }
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}
