#include<bits/stdc++.h>
using namespace std;
string Rc,Rz,Xc,Xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Rc>>Rz>>Xc>>Xz;
	if(Rc==Xc){
		
		if(Rz[0]==Xz[0]&&Rz[1]==Xz[1]){
			
			if(Rz[2]=='D'||Rz[2]=='F'){
				if(Xz[2]=='D'||Xz[2]=='F'){
					cout<<"1111";
				}
				else{
					cout<<"1100";
				}
			}
			else if(Rz[2]=='A'||Rz[2]=='B'||Rz[2]=='C'){
				if(Xz[2]=='A'||Xz[2]=='B'||Xz[2]=='C'){
					if((Rz[2]=='A'&&Xz[2]=='B')||(Rz[2]=='B'&&Xz[2]=='A')||(Rz[2]=='B'&&Xz[2]=='C')||(Rz[2]=='C'&&Xz[2]=='B')){
						cout<<"1111";
					}
					else{
						cout<<"1110";
					}
				}
				else{
					cout<<"1100";
				}
			}
		}
		else{
			cout<<"1000";
		}
		
	}
	else{
		cout<<"0000";
	}
	return 0;
}
