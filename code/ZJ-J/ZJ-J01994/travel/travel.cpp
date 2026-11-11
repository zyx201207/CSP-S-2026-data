#include <iostream>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string c1,s1,c2,s2;	
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	cin>>c1>>s1>>c2>>s2;
	int Tanty1,Tanty2;
	Tanty1=(s1[0]-'0')*10+(s1[1]-'0');
	Tanty2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<1;
		if(Tanty1==Tanty2){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]>='D')){
				cout<<1;
				if(s1[2]>='D'&&s2[2]>='D'){
					cout<<1;
				}else if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
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
	freopen("travel.out","w",stdout);
	return 0;
}