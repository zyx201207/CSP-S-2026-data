#include<bits/stdc++.h>
using namespace std;

int chk1(string x,string y) {
	if(x != y) return 0;
	else return 1;
}

int chk2(string x,string y) {
	if(x[0] == y[0] && x[1] == y[1]) return 1;
	else return 0;
}

int chk3(string x,string y) {
	if((x[2] >= 'A' && x[2] <= 'C' &&
	    y[2] >= 'A' && y[2] <= 'C') ||
	   ((x[2] == 'D' && y[2] == 'F') ||  (
	     x[2] == 'F' && y[2] == 'D'))){
	     	return 1;
		 }
	else return 0;
}

int chk4(string x,string y) {
	if(x[2] >= 'A' && x[2] <= 'C' && y[2] >= 'A' && y[2] <= 'C'){
		if(abs(x[2] - y[2]) == 1) return 1;
	}
	else if((x[2] == 'D' && y[2] == 'F') ||  (x[2] == 'F' && y[2] == 'D')){
		return 1;
	}
	else return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(chk1(c1,c2)){
		cout << 1;
		if(chk2(s1,s2)){
			cout << 1;
			if(chk3(s1,s2)){
				cout << 1;
				if(chk4(s1,s2)){
					cout << 1;
				}
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	
	return 0;
} 
