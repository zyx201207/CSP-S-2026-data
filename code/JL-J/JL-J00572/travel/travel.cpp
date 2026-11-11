#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a,b;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a=s1[0]+s1[1];
		b=s2[0]+s2[1];
		if(a==b){
			cout<<1;
			bool flag=false;
			if(char(s1[2])=='A' or char(s1[2])=='B' or char(s1[2])=='C'){
				if(char(s2[2])=='A' or char(s2[2])=='B' or char(s2[2])=='C'){
					flag=true;
				}
			}
			else{
				if(char(s2[2])=='D' or char(s2[2])=='E'){
					flag=true;
				}
			}
			if(flag){
				cout<<1;
				if(abs(char(s1[2])-char(s2[2])) != 2){
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
