#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
		string e;
		string f;
		e = (char)b[0] + (char)b[1];
		f = (char)d[0] + (char)d[1];
		if(e == f){
			cout << 1;
			char k = b[2],t = d[2];
			if(min(k,t) == 'D' && max(k,t) == 'F'){
				cout << 11;
			}else if('A' <= min(k,t) && max(k,t) <= 'C'){
				cout << 1;
				if(min(k,t) == 'A' && max(k,t) == 'C'){
					cout << 0;
				}else{
					cout << 1;
				}
			}else{
				cout << 0 << 0;
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
}
