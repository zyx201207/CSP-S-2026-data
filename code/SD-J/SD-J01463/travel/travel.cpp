#include<bits/stdc++.h>
using namespace std;
string che1,zuo1,che2,zuo2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>zuo1>>che2>>zuo2;
	if(che1==che2){
		cout<<1;
		if(((zuo1[0]-'0')+(zuo1[1]-'0'))==((zuo2[0]-'0')+(zuo2[1]-'0'))){
			cout<<1;
			if((zuo1[2]<='C'&&zuo2[2]<='C')){
				cout<<1;
				if(abs(zuo1[2]-zuo2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if((zuo1[2]>'C'&&zuo2[2]>'C')){
				cout<<11;
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
