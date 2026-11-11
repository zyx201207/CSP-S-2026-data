#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cc1=10*(c1[0]-'0')+c1[1]-'0',cc2=10*(c2[0]-'0')+c2[1]-'0',f1=1,f2=1,f3=1;
	if(cc1==cc2){
		cout<<1;
	}else{
		cout<<0;
		f1=0;
	}
	int ss1=10*(s1[0]-'0')+s1[1]-'0',ss2=10*(s2[0]-'0')+s2[1]-'0';
	if(ss1==ss2&&f1==1){
		cout<<1;
	}else{
		cout<<0;
		f2=0;
	}
	int sss1=s1[2]-'A'+1,sss2=s2[2]-'A'+1;
	if(((sss1<=3&&sss2<=3)||(sss1>3&&sss2>3))&&f1==1&&f2==1){
		cout<<1;
	}else{
		cout<<0;
		f3=0;
	}
	if(abs(sss1-sss2)==1&&f1==1&&f2==1&&f3==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
