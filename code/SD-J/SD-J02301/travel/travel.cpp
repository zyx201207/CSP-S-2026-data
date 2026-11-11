#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int a1=0,a2=0;
		char d1=s1[2],d2=s2[2];
		a1=(s1[0]-'0')*10+s1[1]-'0';
		a2=(s2[0]-'0')*10+s2[1]-'0';
		if(a1==a2){
			cout<<1;
			if((d1>='D'&&d2>='D')||(d1<='C'&&d2<='C')){
				cout<<1;
				if(abs(d1-d2)==1){
					cout<<1;
				}
				else{
					cout<<0;
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
