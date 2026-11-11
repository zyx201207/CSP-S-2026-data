#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string z1,s1,z2,s2;
	cin>>z1>>s1>>z2>>s2;
	int c1,c2;
	if(z1[0]=='0'&&z1[1]>0){
		c1=z1[1]-'0';
	}else{
		c1=(z1[0]-'0')*10+z1[1]-'0';
	}
	if(z2[0]=='0'&&z2[1]>0){
		c2=z2[1]-'0';
	}else{
		c2=(z2[0]-'0')*10+z2[1]-'0';
	}
	
	int sx1,sx2;
	if(s1[0]=='0'&&s1[1]>0){
		sx1=s1[1]-'0';
	}else{
		sx1=(s1[0]-'0')*10+s1[1]-'0';
	}
	if(s2[0]=='0'&&s2[1]>0){
		sx2=s2[1]-'0';
	}else{
		sx2=(s2[0]-'0')*10+s2[1]-'0';
	}
	if(c1==c2){
		cout<<1;
		if(sx1==sx2){
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
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
	return 0;
}