
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int a=0,b=0;
	for(int i=0;i<2;i++){
		a=a*10+s1[i]-'0';
		b=b*10+s3[i]-'0';
	}
	if(a!=b) {
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	a=0,b=0;
	for(int i=0;i<2;i++){
		a=a*10+s2[i]-'0';
		b=b*10+s4[i]-'0';
	}
	if(a==b)cout<<"1";
	else{
		 cout<<"000";
		return 0;
	}
	char c,d;
	int f;
	c=s2[2] ,d=s4[2];
	if(c>='A'&&c<='C'&&d>='A'&&d<='C') f=1;
	else if(c>='D'&&c<='F'&&d>='D'&&d<='F') f=1;
	else f=0;
	cout<<f;
	if(f&&abs(c-d)==1) cout<<"1";
	else cout<<"0";
	
	return 0;
}

