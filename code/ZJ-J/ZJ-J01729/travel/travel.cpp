#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1;
	string b1;
	char a2,a3,a4;
	char b2,b3,b4;
	cin>>a1>>a2>>a3>>a4>>b1>>b2>>b3>>b4;
	if(a1==b1){
		cout<<1;
		if(a2+a3==b2+b3){
			cout<<1;
			if((a4>='D'&&b4>='D')||(a4<='C'&&b4<='C')){
				cout<<1;
				if(abs(a4-b4)==1||(a4=='F'&&b4=='D')||(a4=='D'&&b4=='F')){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
