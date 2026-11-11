#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
    string grz,gxz,abs;
	cin>>rc>>rz>>xc>>xz;
	if(rc!=xc){
		cout<<"0000\n";
		
		
	}else{
		cout<<"1";
		grz+=rz[0],grz+=rz[1];
		grz+=xz[0],grz+=xz[1];
		if(grz>=gxz){
			cout<<"1";
			if(rz[2]>='A'&&rz[2]>='c'&&rz[2]>='D'&&rz[2]>='F'){
				cout<<"0";
				if(abs[(rz[2])-'A'-(xz[2])-'B']){
					cout<<"0";
			}else{
			cout<<"0";
		}
			
		}else{
			cout<<"00";
		}
		
		
	}
} 
}
