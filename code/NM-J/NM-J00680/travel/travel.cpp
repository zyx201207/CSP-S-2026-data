#include<bits/stdc++.h>
using namespace std;
string Rc,Rz,Xc,Xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Rc>>Rz>>Xc>>Xz;
	if(Rc==Xc){
		cout<<"1";
		string Rpai,Xpai;
		Rpai=Rz[0];
		Rpai+=Rz[1];
		Xpai=Xz[0];
		Xpai+=Xz[1];
		if(Rpai==Xpai){
			cout<<"1";
			if(Rz[2]=='A'||Rz[2]=='B'||Rz[2]=='C'){
				if(Xz[2]=='D'||Xz[2]=='F') cout<<"00";
				else if(Xz[2]=='A'||Xz[2]=='B'||Xz[2]=='C'){
					cout<<"1";
					if(Rz[2]=='A'&&Xz[2]=='B'){
						cout<<"1";
					}else 
					if(Rz[2]=='B'&&((Xz[2]=='A')||(Xz[2]=='C'))){
						cout<<"1";
					}else 
					if(Rz[2]=='C'&&Xz[2]=='B'){
						cout<<"1";
					}else cout<<"0";
				}
			}else{
				if(Xz[2]=='D'||Xz[2]=='F'){
					cout<<"1";
					if(Rz[2]=='D'&&Xz[2]=='F'){
						cout<<"1";
					}else 
					if(Rz[2]=='F'&&Xz[2]=='D'){
						cout<<"1";
					}else cout<<"0";
				}else cout<<"00";
			}
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
