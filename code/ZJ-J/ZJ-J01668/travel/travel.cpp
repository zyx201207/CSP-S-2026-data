#include <bits/stdc++.h>
using namespace std;
int c,cc;
string sn,ssn;
int check(char x,char y){
	if(abs(y-x)==1||(y=='D'&&x=='F')||(x=='D'&&y=='F')) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>sn>>cc>>ssn;
	int s=(sn[0]-'0')*10+sn[1]-'0',ss=(ssn[0]-'0')*10+ssn[1]-'0';
	char n=sn[2],m=ssn[2];
	if(c!=cc) cout<<"0000";
	else{
		cout<<1;
		if(s!=ss) cout<<"000";
		else{
			cout<<1;
			if((n>='D'&&m<='C')||(n<='C'&&m>='D')) cout<<"00";
			else{
				cout<<1<<check(n,m);
			}
		}
	}
	return 0;
} 