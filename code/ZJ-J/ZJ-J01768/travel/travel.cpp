#include<bits/stdc++.h>
using namespace std;
string ca,cb,zwa,zwb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>zwa>>cb>>zwb;
	int lsa,lsb,sza,szb;
	if(zwa[2]=='A'||zwa[2]=='B'||zwa[2]=='C'){
		lsa=0;
	}
	else{
		lsa=1;
	}
	if(zwb[2]=='A'||zwb[2]=='B'||zwb[2]=='C'){
		lsb=0;
	}
	else{
		lsb=1;
	}
	sza=zwa[2]-'A';
	szb=zwb[2]-'A';
	if(ca[0]==cb[0]&&ca[1]==cb[1]){
		cout<<1;
		if(zwa[0]==zwb[0]&&zwa[1]==zwb[1]){
			cout<<1;
			if(lsa==lsb){
				cout<<1;
				if(abs(sza-szb)==1){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<0<<0;
				return 0;
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
