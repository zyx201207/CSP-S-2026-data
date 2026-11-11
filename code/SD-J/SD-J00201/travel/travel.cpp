#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	int pai1=(s1[0]-'0')*10+(s1[1]-'0');
	int pai2=(s2[0]-'0')*10+(s2[1]-'0');
	if(pai1==pai2){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	int zuo1=s1[2]-'A';
	int zuo2=s2[2]-'A';
	if(((zuo1==0||zuo1==1||zuo1==2)&&(zuo2==1||zuo2==2||zuo2==0))||((zuo1==3||zuo1==4)&&(zuo2==3||zuo2==4))){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if((zuo1==0&&zuo2==1)||(zuo1==1&&(zuo2==0||zuo2==2))||(zuo1==2&&(zuo2==1||zuo2==3))||(zuo1==3&&(zuo2==2||zuo2==4))||(zuo1==4&&zuo2==3)){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
