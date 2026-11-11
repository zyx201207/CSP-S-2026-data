#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	int rc = (b[0]-'0')*10+(b[1]-'0');char r = b[2];
	int xc = (d[0]-'0')*10+(d[1]-'0');char x = d[2];
	if(a == c){
		cout << 1;
		if(rc == xc){
			cout << 1;
			if(r <= 'C' && x <= 'C' || r >= 'D' && x >= 'D'){
				cout << 1;
				if(abs(x-r) == 1)cout << 1;
				else cout << 0;
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else {
		cout << "0000";
	}
		
	
	return 0;
} 
