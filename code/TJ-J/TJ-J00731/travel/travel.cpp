#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+7;
string a, b, c, d;
int rcx, rline, xcx, xline;
char rst, xst;
bool check(char x, char y){
	if((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C'))
		return true;
	else if((x == 'E' || x == 'F') && (y == 'E' || y == 'F'))
		return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	
	rcx = (a[0]-'0')*10 + (a[1]-'0');
	rline = (b[0]-'0')*10 + (b[1]-'0');
	rst = b[2];
	xcx = (c[0]-'0')*10 + (c[1]-'0');
	xline = (d[0]-'0')*10 + (d[1]-'0');
	xst = d[2];
	
	if(rcx == xcx){
		cout << 1;
		if(rline == xline){
			cout << 1;
			if(check(rst,xst)){
				cout << 1;
				if(max((int)rst,(int)xst) - min((int)rst,(int)xst) == 1)
					cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}	
	else cout << "0000";
	
	return 0;
} 
