#include<bits/stdc++.h>
using namespace std;
int main(){
	int rc,xc;
	string rw,xw;
	cin>>rc>>rw>>xc>>xw;
	if(rc==xc){
		cout<<'1'; 
		if(rw[0]==xw[0]&&rw[1]==xw[1]){
			cout<<'1';
			if(rw[2]=='C'&&xw[2]=='D'||rw[2]=='D'&&xw[2]=='C'){
				cout<<"00";
			}else{
				cout<<'1';
				if(int(rw[2])-1==int(xw[2])||int(rw[2])+1==int(xw[2])){
					cout<<'1';
				}else{
					cout<<"0";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
