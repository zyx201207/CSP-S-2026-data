#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=s1[1];
	int b=s2[1];
	char x=s1[2];
	char y=s2[2];
	if(c1==c2){
		cout<<"1";
		if(a==b){
			cout<<"1";
			if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
				cout<<"1";
				if(x=='A'&&y=='B'){
					cout<<"1";
				}
				else if(x=='B'&&(y=='A'||y=='C')){
					cout<<"1";
				}
				else if(x=='C'&&y=='B'){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(x>='D'&&x<='F'&&y>='D'&&y<='F'){
				cout<<"11";
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
