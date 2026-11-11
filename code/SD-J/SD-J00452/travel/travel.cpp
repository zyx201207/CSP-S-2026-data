#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
char s1[4];
char s2[4];
int num=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2){
		num++;
		cout<<"1";	
	}
	else cout<<"0";
	if(num&&s1[1]==s2[1]&&s1[2]==s2[2]){
		num++;
		cout<<"1";	
	}   
	else cout<<"0";
	int cnt=abs(int(s1[3]-s2[3]));
	char cnt1;
	char cnt2;
	char cnt3=1;
	char cnt4=1;
	if(num==2&&int(s1[3]-'A')<=2&&int(s2[3]-'A')<=2){
		cnt1='1';
		num++;
		cout<<cnt1;
	}
	else 
	if(num==2&&int(s1[3]-'D')>=0&&int(s2[3]-'D')>=0){
		cnt2='1';
		num++;
		cout<<cnt2;
	}
	else cout<<"0";
	if(s1[3]=='A'&&s2[3]=='C'){
		cnt3=0;
	}
	if(s1[3]=='C'&&s2[3]=='A'){
		cnt4=0;
	}
	if(num==3&&cnt3&&cnt4){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
