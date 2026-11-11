#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trvael.in","r",stdin);
	freopen("trvael.out","w",stdout);
	string co,so,ct,st;
	cin>>co>>so>>ct>>st;
	if(co==ct){
		cout<<"1";
		if(so[0]==st[0] & so[1]==st[1]){
			cout<<"1";
			if(so[2]=='F' || so[2]=='D'){
				if(st[2]=='F' || st[2]=='D'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else if(st[2]=='A' || st[2]=='B' || st[2]=='C'){
				cout<<"1";
				if(so[2]=='B'){
					cout<<"1";
				}else if(st[2] !='B'){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}