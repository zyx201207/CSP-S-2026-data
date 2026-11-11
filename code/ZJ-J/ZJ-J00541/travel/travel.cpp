#include <bits/stdc++.h>
using namespace std;
string cr,cx,zr,zx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>cr>>zr>>cx>>zx;
    if(cr==cx){
    	cout<<'1';
    	if(zr[0]==zx[0]&&zr[1]==zx[1]){
    		cout<<'1';
    		if((zr[2]=='A'&&zx[2]=='B')||(zr[2]=='B'&&zx[2]=='C')||(zr[2]=='A'&&zx[2]=='C')||(zr[2]=='C'&&zx[2]=='A')||(zr[2]=='C'&&zx[2]=='B')||(zr[2]=='B'&&zx[2]=='A')||(zr[2]=='D'&&zx[2]=='E')||(zr[2]=='E'&&zx[2]=='D')){
    			cout<<'1';
    			if((zr[2]=='A'&&zx[2]=='B')||(zr[2]=='B'&&zx[2]=='C')||(zr[2]=='C'&&zx[2]=='B')||(zr[2]=='B'&&zx[2]=='A')||(zr[2]=='D'&&zx[2]=='C')||(zr[2]=='C'&&zx[2]=='D')){
    				cout<<'1';
				}else{
					cout<<'0';
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

