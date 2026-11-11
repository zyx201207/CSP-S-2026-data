#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	char p1=s2[0]+s2[1];
	char p2=s4[0]+s4[1];
	if(p1==p2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char z1=s2[2];
	char z2=s4[2];
	if((z1<='C'&&z2<='C')||(z1>='D'&&z2>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	int ch=z1-z2;
	int cha=abs(ch);
	if(cha<=1){
		cout<<"1";
	}else if((z1=='D'&&z2=='F')||(z1=='F'&&z2=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

