#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cty1,cty2;
	string sl1,sl2;
	cin>>cty1>>sl1>>cty2>>sl2;
	if(cty1==cty2){
		cout<<'1';
		if(sl1[0]+sl1[1]==sl2[0]+sl2[1]){
			cout<<'1';
			if((sl1[2]<='C'&&sl2[2]<='C')||(sl1[2]>='D'&&sl2[2]>='D')){
				cout<<'1';
				if(sl1[2]==sl2[2]+1||sl2[2]==sl1[2]+1){
					cout<<'1';
				} 
				else{
					cout<<'0';
				}
			}
			else{
				cout<<"00";
			}
	}
		else{
			cout<<"000";
		}
}
	else{
		cout<<"0000";
	}
	
	return 0;
}
