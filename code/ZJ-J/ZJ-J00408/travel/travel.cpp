#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string x, y, a, b;
	cin >> x >> a >> y >> b;
	if(x == y){
		cout << 1;
//		cout << "tcx";
		if(a[0] == b[0] && a[1] == b[1]){
			cout << 1;
//			cout << "tp";
			if(((a[2] == 'A' || a[2] == 'B' || a[2] == 'C') && (b[2] == 'A' || b[2] == 'B' || b[2] == 'C')) || ((a[2] == 'D' || a[2] == 'F') && (b[2] == 'D' || b[2] == 'F')) ){
				cout << 1;
//				cout << "tc";
				if((a[2] == 'A' && b[2] == 'B') || (a[2] == 'B' && b[2] == 'C') || (a[2] == 'D' && b[2] == 'F')   ||   (b[2] == 'A' && a[2] == 'B') || (b[2] == 'B' && a[2] == 'C') || (b[2] == 'D' && a[2] == 'F') ){
					cout << 1;
//					cout << "xl";
				}else{
					cout << 0;
				}	
			}
			else{
				cout << "00";
			}
			
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	
	return 0;
}
/*

*/
