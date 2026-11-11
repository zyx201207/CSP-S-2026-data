#include<bits/stdc++.h>
using namespace std;
int main(){
	string x1,x2,y1,y2;
	int l1,l2;
	cin>>x1>>y1>>x2>>y2;
	if(y1[2]>='A'&&y1[2]<='C')l1=1;
	else l1=2;
	if(y2[2]>='A'&&y2[2]<='C')l2=1;
	else l2=2;
	if(x1==x2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
		if(y1[0]==y2[0]&&y1[1]==y2[1]){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
	if(l1==l2){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(l1!=l2){
		cout<<"0";
	}else{
		if(l1==1){
			if(y1[2]=='A'&&y2[2]=='B'||y1[2]=='B'&&y2[2]=='C'){
				cout<<"1";
			}else cout<<"0";
		}else{
			cout<<"1";
		}
	}
	return 0;
}
