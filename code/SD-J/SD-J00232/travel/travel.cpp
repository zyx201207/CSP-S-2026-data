#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
string q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin >> a >> c >> q >> b >> d >> w;
    if (a == b){
    	cout << "1";
    	if (c == d){
    		cout << "1";
    		if ((q[0] <= 'C' && w[0] <= 'C')||(q[0] >= 'D' && w[0] >= 'D')){
    			cout << "1";
    			if (q[0] + 1 == w[0] || q[0]-1 == w[0]){
    				cout << "1";
				}
				else {
					cout << "0";
					return 0;
				}
			}
			else {
				cout << "00";
				return 0;
			}
		}
		else{
			cout << "000";
			return 0;
		}
	} 
    else {
    	cout << "0000";
    	return 0;
	}
	return 0;
}
