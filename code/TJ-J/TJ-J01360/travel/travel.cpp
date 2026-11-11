#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	char a=s1[0],b=s1[1],c=s1[2],d=s2[0],e=s2[1],f=s2[2];
	//a=s1[0];
	//b=s1[1];
	//c=s1[2];
	//d=s2[0];
	//e=s2[1];
	//f=s2[2];02 01A 03 01A

	if(c1==c2){
		cout<<"1";
		if(a==d&&b==e){
			cout<<"1";
			if(((c=='A'||c=='B'||c=='C')&&(f=='A'||f=='B'||f=='C'))||((c=='D'||c=='F')&&(f=='D'||f=='F'))){
				cout<<"1";
				if((c=='A'&&f=='B')||(c=='B'&&f=='A')||(c=='C'&&f=='B')||(c=='B'&&f=='c')||(c=='D'&&f=='F')||(c=='F'&&f=='D')){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	
	return 0;
	//It's~okay!
}
