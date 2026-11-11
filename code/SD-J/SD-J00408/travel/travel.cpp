#include<bits/stdc++.h>
using namespace std;
int ac,bc,ap,bp,azz,bzz;
char az,bz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>ap>>az>>bc>>bp>>bz;
	if(az=='A'||az=='C'||az=='B')azz=0;
	else azz=1;
	if(bz=='A'||bz=='C'||bz=='B')bzz=0;
	else bzz=1;
	if(ac==bc){
		cout<<1;
		if(ap==bp){
			cout<<1;
			if(azz==bzz){
				cout<<1;
				if(az+1==bz||bz+1==az)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
