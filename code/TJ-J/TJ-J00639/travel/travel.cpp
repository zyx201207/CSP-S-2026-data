#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	string m;
	int r;
	string p;
	if(n == r){
		if(m[0] == p[0]  && m[1] == p[1]){
			if(m[2] = "A"&&p[2] = "B" || m[2] = "B"&&p[2] = "A" || m[2] = "B"&&p[2] = "C" || m[2] = "A"&&p[2] = "C" || m[2] = "D"&&p[2] = "F" || m[2] = "F"&&p[2] = "D" || m[2] = "C"&&p[2] = "D"){
				if(m[2] != "C"&&p[2] != "D" || m[2] != "D"&&p[2] != "C"){
					cout << "1111" << endl;
				}	else
					cout << "1110" << endl;
			}	else
				cout << "1100" << endl;
		}	else
			cout << "1000" << endl;	
	}	else
		cout << "0000" << endl;
	return 0;
	}
