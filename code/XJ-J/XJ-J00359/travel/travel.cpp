#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int z1q=0,z1h=0,z2q=0,z2h=0;
	z1q=c1[0]-'0';
	z1h=c1[1]-'0';
	z2q=c2[0]-'0';
	z2h=c2[1]-'0';
	if(z1q==z2q&&z1h==z2h){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	z1q=s1[0]-'0';
	z1h=s1[1]-'0';
	z2q=s2[0]-'0';
	z2h=s2[1]-'0';
	if(z1q==z2q&&z1h==z2h){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int a=0,b=0;
	a=s1[2]-'A';
	b=s2[2]-'A';
	if((a<=2&&b<=2)||(a>2&&b>2)){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a-1==b||b-1==a){
		cout<<1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}