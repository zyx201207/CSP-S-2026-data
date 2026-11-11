#include<iostream>
using namespace std;
int xiaoR,xiaoX;
string Rche,Xche;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xiaoR>>Rche>>xiaoX>>Xche;
	if(xiaoR==xiaoX){
		cout<<1;
		int xiaoA,xiaoB;
		xiaoA=(Rche[0]-'0')*10+(Rche[1]-'0');
		xiaoB=(Xche[0]-'0')*10+(Xche[1]-'0');
		if(xiaoA==xiaoB){
			cout<<1;
			if(((Rche[2]=='A')&&(Xche[2]=='B'))||((Rche[2]=='A')&&(Xche[2]=='C'))||((Rche[2]=='B')&&(Xche[2]=='C'))||((Rche[2]=='B')&&(Xche[2]=='A'))||((Rche[2]=='C')&&(Xche[2]=='A'))||((Rche[2]=='C')&&(Xche[2]=='B'))||((Rche[2]=='D')&&(Xche[2]=='F'))||((Rche[2]=='F')&&(Xche[2]=='D'))){
				cout<<1;
				if(((Rche[2]=='A')&&(Xche[2]=='B'))||((Xche[2]=='B')&&(Xche[2]=='A'))||((Rche[2]=='C')&&(Xche[2]=='B'))||((Xche[2]=='B')&&(Xche[2]=='C'))||((Rche[2]=='D')&&(Xche[2]=='F'))||((Xche[2]=='F')&&(Xche[2]=='D'))){
					cout<<1;
				}else{
					cout<<0;
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
