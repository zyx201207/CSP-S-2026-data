#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,a1,a2,b,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		a1=s2[0]-'0';
		a2=s2[1]-'0';
		b1=s4[0]-'0';
		b2=s4[1]-'0';
		if(a1==b1&&a2==b2){
			cout<<"1";
			a=(int)s2[2];
			b=(int)s4[2];
			if(a>=65&&a<=67&&b>=65&&b<=67){
				cout<<"1";
				if(a==b+1||b==a+1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(a>=68&&a<=70&&b>=68&&b<=70){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
				cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
	}
