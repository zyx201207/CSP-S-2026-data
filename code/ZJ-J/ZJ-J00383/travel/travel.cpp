#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int f1=0,f2=0,f3=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<0;
		f1=1;
	}
	if((s1[0]*10+s1[1])==(s2[0]*10+s2[1])&&f1==0)cout<<1;
	else{
		cout<<0;
		f2=1;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&f2==0)cout<<1;
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&f2==0)cout<<1;
	else{
		f3=1;
		cout<<0;
	}
	if(f3==1)cout<<0;
	else{
		int x=s1[2]-'A',y=s2[2]-'A';
		if(x-y==1||x-y==-1)cout<<1;
		else cout<<0;
	}
	
	return 0;
}