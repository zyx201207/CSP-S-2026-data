#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int x,y;
	string xx,yy;
	cin >> x >> xx >> y >> yy;
	if(x==y){
		if(x>1 && x<16 && y>1 && y<16){
			cout << 1;
			if(xx[0]==yy[0] && xx[1]==yy[1]){
				cout << 1;
				if(xx[2]=='A'){
					if(yy[2]=='B'){
						cout << 1 << 1;
						return 0;
					}
					else if(yy[2]=='C'){
						cout << 1 << 0;
						return 0;
					}
					else{
						cout << 0 << 0;
						return 0;
					}
				}
				else if(xx[2]=='B'){
					if(yy[2]=='A' || yy[2]=='C'){
						cout << 1 << 1;
						return 0;
					}
					else{
					
					}	cout << 0 << 0;
				}
				else if(xx[2]=='C'){
					if(yy[2]=='A'){
						cout << 1 << 0;
						return 0;
					}
					else if(yy[2]=='B'){
						cout << 1 << 1;
						return 0;
					}
					else{
						cout << 0 << 0;
						return 0;
					}	
				}
				else if(xx[2]=='D'){
					if(yy[2]=='E'){
						cout << 1 << 1;
						return 0;
					}
					else{
						cout << 0 << 0;
						return 0;
					}	
				}
				else if(xx[2]=='E'){
					if(yy[2]=='D'){
						cout << 1 << 1;
						return 0;
					}
					else{
						cout << 0 << 0;
						return 0;
					}
				}
			}	
			else{
				cout << 0 << 0 << 0;
				return 0;
			}
		}
		else{
			cout << 0 << 0 << 0 << 0;
			return 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	return 0;
}
