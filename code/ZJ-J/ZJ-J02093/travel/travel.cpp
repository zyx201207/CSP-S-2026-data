#include<bits/stdc++.h>
using namespace std;
int c1,c2,x,y;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	s3=s1[0]+s1[1];
	s4=s2[0]+s2[1];
	if(s3!=s4){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	x=s1[2]-'A'+1;
	y=s2[2]-'A'+1;
	if(x<=3){
		if(y>3){
			cout<<"00";
			return 0;
		}
		cout<<1;
		if(abs(x-y)==1){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	else{
		if(y<=3){
			cout<<"00";
			return 0;
		}
		cout<<"1";
		if(abs(x-y)==1){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
}