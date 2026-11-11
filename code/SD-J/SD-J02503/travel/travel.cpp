#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a=1;
	else{
		cout<<"0000";
		return 0;
	}
	int a1=s1[0]-'0',a2=s1[1]-'0',a3=s2[0]-'0',a4=s2[1]-'0';
	char a5=s1[2],a6=s2[2];
	if(a1==a3&&a2==a4)b=1;
	else{
		cout<<"1000";
		return 0;
	}
	if(a5<='C'&&a6<='C'||a5>='D'&&a6>='D')c=1;
	else{
		cout<<"1100";
		return 0;
	}
	int a7=abs(a5-a6);
	if(a7==1)d=1;
	else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
