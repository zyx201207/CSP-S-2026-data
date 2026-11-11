#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char a3,b3;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	a1=s1[1]-48+(s1[0]-48)*10,b1=s3[1]-48+(s3[0]-48)*10;
	if(a1==b1){
		cout<<1;
		a2=s2[1]-48+(s2[0]-48)*10,b2=s4[1]-48+(s4[0]-48)*10;
		if(a2==b2){
			cout<<1;
			a3=s2[2],b3=s4[2];
			if((a3>='A'&&a3<='C'&&b3>='A'&&b3<='C')||(a3>='D'&&a3<='F'&&b3>='D'&&b3<='F')){
				cout<<1;
				if(abs(a3-b3)==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
//02 01A 02 01B
