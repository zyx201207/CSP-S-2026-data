#include<bits/stdc++.h>
using namespace std;
string R1,R2,X1,X2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R1>>R2>>X1>>X2;
	if(R1==X1) cout<<"1";
	else cout<<"0";
	if(R1==X1&&R2[0]==X2[0]&&R2[1]==X2[1]) cout<<"1";
	else cout<<"0";
	int a,b;
	if(R2[2]>='A'&&R2[2]<='C') a=1;
	else a=2;
	if(X2[2]>='A'&&X2[2]<='C') b=1;
	else b=2;
	if(R1==X1&&R2[0]==X2[0]&&R2[1]==X2[1]&&a==b) cout<<"1";
	else cout<<"0";
	int x=abs(R2[2]-X2[2]);
	if(R1==X1&&R2[0]==X2[0]&&R2[1]==X2[1]&&a==b&&x==1) cout<<"1";
	else cout<<"0";
	return 0;
}