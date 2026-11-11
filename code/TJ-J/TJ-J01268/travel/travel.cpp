#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a == c){
		if (b[0] == d[0] && b[1] == d[1]){
			int mn = min(d[2],b[2]),mx = max(d[2],b[2]);
			if (mn <= 'C' && mx >= 'D') cout << "1100";
			else{
				if (mn == 'A' && mx == 'C') cout << "1110";
				else cout << "1111";
			}
		}
		else cout << "1000"; 
	}
	else cout << "0000";
	return 0;
}
