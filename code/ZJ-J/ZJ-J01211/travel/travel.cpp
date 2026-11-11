#include<bits/stdc++.h>

using namespace std;

string chex1,seat1,chex2,seat2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>chex1>>seat1>>chex2>>seat2;
	if(chex1==chex2) {
		if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]) {
			if((seat1[2]<='C'&&seat2[2]<='C')||(seat1[2]>'C'&&seat2[2]>'C')) {
				int delta=int(seat1[2]-seat2[2]);
				if(delta==1||delta==-1) {
					cout<<"1111";
				} else {
					cout<<"1110";
				}
			} else {
				cout<<"1100";
			}
		} else {
			cout<<"1000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}