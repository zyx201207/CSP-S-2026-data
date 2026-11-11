#include<bits/stdc++.h>
using namespace std;
string cx1,zw1,cx2,zw2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2){
		if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]){
			if((zw1[2]<='C'&&zw2[2]<='C')||(zw1[2]>='D'&&zw2[2]>='D')){
				if(abs(int(zw1[2])-int(zw2[2]))==1){
		if((zw1[2]=='D'&&zw2[2]=='F')||(zw1[2]=='F'&&zw2[2]=='D')){
					cout<<"1110";
			}
					cout<<"1111";
			}else{
					cout<<"1110";
				}
			}
	else{
		cout<<"1100";
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
