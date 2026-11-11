#include<bits/stdc++.h>
using namespace std;
string sc,sh,rc,rh;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	cin>>sc>>sh>>rc>>rh;
	if(sc==rc){
		cout<<1;
		string sp="",rp="";
		sp+=sh[0];
		sp+=sh[1];
		rp+=rh[0];
		rp+=rh[1];
		if(sp==rp){
			cout<<1;
			int a=0,b=0;
			a=sh[2]-'A';
			b=rh[2]-'A';
			if(a<3&&b<3){
				cout<<1;
				if(abs(a-b)==1){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else if(a>2&&b>2){
				cout<<11;
				return 0;
			}
			else{
				cout<<"00";
				return 0; 
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
} 
