#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r",srdin);
	//freopen("travel.out","w",srdout);
	int r1,r2;
	char r11[10];
	char r22[10];
	cin >> r1;
	for(int i =0;i<3;i++){
		cin >> r11[i];
	}
	cin >> r2;
	for(int i =0;i<3;i++){
		cin >> r22[i];
	}
	if( r1==r2 ){
		cout << "1";
		if(r11[0] == r22[0] && r11[1] == r22[1]){
			cout << "1";
			if((65<=int(r11[2]) && int(r11[2])<=67 && 65<=int(r22[2]) && int(r22[2])<=67) || (68<=int(r11[2]) && int(r11[2])<=69 &&68<=int(r22[2]) && int(r22[2])<=69)){
				cout << "1";
				if(int(r11[2])+1==int(r22[2]) || int(r11[2])==int(r22[2])+1){
					cout << "1";
				}
				else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}