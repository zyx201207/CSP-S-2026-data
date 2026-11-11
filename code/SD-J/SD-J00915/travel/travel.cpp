#include <bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> ca >> sa >> cb >> sb;
	if(ca==cb){
		cout << 1;
		if(sa[0]+sa[1]==sb[0]+sb[1]){
			cout << 1;
			if((sa[2]<='C'&&sb[2]<='C')||(sa[2]>='D'&&sb[2]>='D')){
				cout << 1;
				if((sa[2]=='A'&&sb[2]=='B')||(sa[2]=='B'&&(sb[2]=='A'||sb[2]=='C'))||(sa[2]=='C'&&sb[2]=='B')||(sa[2]=='D'&&sb[2]=='F')||(sa[2]=='F'&&sb[2]=='D')){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
