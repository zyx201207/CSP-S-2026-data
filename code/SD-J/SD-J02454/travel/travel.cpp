#include<bits/stdc++.h>
using namespace std;
int c1,c2,sum1,sum2;
char ams1,ams2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		sum1=s1[0]*10+s1[1];
		sum2=s2[0]*10+s2[1];
		if(sum1==sum2){
			cout<<"1";
			ams1=s1[2];
			ams2=s2[2];
			if((ams1=='A'||ams1=='B'||ams1=='C')&&(ams2=='A'||ams2=='B'||ams2=='C')){
				cout<<"1";
				if((ams1=='A'&&ams2=='B')||(ams2=='A'&&ams1=='B')||(ams1=='C'&&ams2=='B')||(ams1=='B'&&ams2=='C')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if((ams1=='D'||ams1=='F')&&(ams2=='D'||ams2=='F')){
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
