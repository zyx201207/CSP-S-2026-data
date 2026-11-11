#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		int idc2=(c2[0]-'0')*10+c2[1]-'0';
		int idc4=(c4[0]-'0')*10+c4[1]-'0';
		if(idc2==idc4){
			cout<<"1";
			if(c2[2]=='D'||c2[2]=='F'){
				if(c4[2]=='F'||c4[2]=='D')cout<<"11";
				else cout<<"00";
			}
			else{
				if(c4[2]=='A'||c4[2]=='B'||c4[2]=='C'){
					cout<<"1";
					if(abs(c4[2]-c2[2])==1){
						cout<<"1";
					}
					else cout<<"0";
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
