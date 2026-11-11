#include<bits/stdc++.h>
using namespace std;
string cx , sx , cy , sy;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cx >> sx >> cy >> sy;
	if(cx == cy){
		cout << "1";
		int numx = 0 , numy = 0;
		numx = (sx[0] - '0') * 10 + (sx[1] - '0');
		numy = (sy[0] - '0') * 10 + (sy[1] - '0');
		if(numx == numy){
			cout << "1";
			if(sx[2] == 'A'){
				if(sy[2] == 'B'){
					cout << "11";
				}
				else if(sy[2] == 'C'){
					cout << "10";
				}
				else{
					cout << "00";
				}
			}
			if(sx[2] == 'B'){
				if(sy[2] == 'A' || sy[2] == 'C'){
					cout << "11";
				}
				else{
					cout << "00";
				}
			}
			if(sx[2] == 'C'){
				if(sy[2] == 'B'){
					cout << "11";
				}
				else if(sy[2] == 'A'){
					cout << "10";
				}
				else{
					cout << "00";
				}
			}
			if(sx[2] == 'D'){
				if(sy[2] == 'F'){
					cout << "11";
				}
				else{
					cout << "00";
				}
			}
			if(sx[2] == 'F'){
				if(sy[2] == 'D'){
					cout << "11";
				}
				else{
					cout << "00";
				}
			}
			return 0;
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	return 0;
}
/*
CRRC

CR400AF-B
*/
