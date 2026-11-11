#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=c1[0]*10+c1[1],b1=c2[0]*10+c2[1];
	if(a1==b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int a2=s1[0]*10+s1[1],b2=s2[0]*10+s2[1];
	if(a2==b2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int a3=s1[2]-'0'-16,b3=s2[2]-'0'-16;

	if(a3<=3 && b3<=3){
		cout<<1;
	}else if(a3>=4 && b3>=4){
		cout<<1;
	}else{
		cout<<0;
	}
	if(abs(a3-b3)==1){
		if(a3==3 && b3==4){
			cout<<0;
			return 0;
		}else if(a3==4 && b3==3){
			cout<<0;
			return 0;
		}
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
