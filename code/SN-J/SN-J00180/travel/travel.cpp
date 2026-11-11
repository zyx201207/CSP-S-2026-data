#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string r,x,r2,x2;
	cin >> a >> r >> b >> x;
	r2 = r[2];
	x2 = x[2];
	if (a == b){
		if (r[0] == x[0] && r[1] == x[1]){
			if (((r2 == "A" || r2 == "B" || r2 == "C") && (x2 == "A" || x2 == "B" || x2 == "C")) || ((r2 == "D" || r2 == "F") && (x2 == "D" || x2 == "F"))){
				if ((r2 == "A" && x2 == "B") || (r2 == "B" && x2 == "A") || (r2 == "B" && x2 == "C") || (r2 == "C" && x2 == "B")){
					cout << "1111";
				}else if ((r2 == "F" && x2 == "D") || (r2 == "D" && x2 == "F")){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
