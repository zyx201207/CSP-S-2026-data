#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1==c2) ans+="1";
	else{
		cout<<"0000";
		return 0;
	}
	string a1,a2;
	char b1,b2;
	a1=s1[0]+s1[1];
	b1=s1[2];
	a2=s2[0]+s2[1];
	b2=s2[2];
	if(a1==a2) ans+="1";
	else{
		cout<<"1000";
		return 0;
	}
	int f=0;
	if(b1>='A'&&b1<='C'&&b2>='A'&&b2<='C') {
		f=1;
		ans+="1";
	}
	else if(b1>='D'&&b1<='F'&&b2>='D'&&b2<='F'&&b1!='E'&&b2!='E'){
		f=2;
		ans+="1";
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(f==1){
		if(b1=='B'||b2=='B'){
			cout<<"1111";
			return 0;
		}
	}
	if(f==2){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}