#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	ll ca,cb;
	string sa,sb;
	cin >> ca >> sa >> cb >> sb;
	if(ca == cb) {
		cout << "1";
		for(int i = 1;i<2;i++){ 
			if(sa[i] == sb[i]){
			cout << "1";
			for(int i = 2;i<3;i++){
				if(sa[i] == 'A'&&sb[i] == 'B'||sa[i] == 'A'&&sb[i] == 'C'
				||sa[i] == 'B'&&sb[i] == 'C'||sa[i] == 'B'&&sb[i] == 'A'
				||sa[i] == 'C'&&sb[i] == 'A'||sa[i] == 'C'&&sb[i] == 'B'
				||sa[i] == 'D'&&sb[i] == 'F'||sa[i] == 'F'&&sb[i] == 'D'){
					cout << "1";
					if(sa[i] == 'A'&&sb[i] == 'B'
					||sa[i] == 'B'&&sb[i] == 'C'
					||sa[i] == 'B'&&sb[i] == 'A'
					||sa[i] == 'C'&&sb[i] == 'B'
					||sa[i] == 'D'&&sb[i] == 'F'
					||sa[i] == 'F'&&sb[i] == 'D'){
						cout << "1";
					return 0;
					}else{
						cout << "0";
						return 0 ;}
				}else{
					cout << "00";
					return 0;
				}
			}
			}else{cout << "000";
			return 0;}
		}
	}else {
	cout << "0000";
	 return 0;
	}
	
	return 0;
}

