#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int a1=0,a2=0;
	a1=(s2[0]-'0')*10+s2[1]-'0';
	a2=(s4[0]-'0')*10+s4[1]-'0';
	int c1,c2;
	c1=s2[2]-'A',c2=s4[2]-'A';
	if(a1==a2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((c1<=2&&c2<=2)||(c1>=3&&c2>=3)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((c1==0&&c2==1)||(c2==0&&c1==1)||(c2==1&&c1==2)||(c1==1&&c2==2)||(c1==3&&c2==5)||(c1==5&&c2==3)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}