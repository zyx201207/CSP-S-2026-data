#include <iostream>
#include <string>
using namespace std;
char b[10],b2[10];

int b0[10],b1[10];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a2;
	cin>>a>>b>>a2>>b2;
	if(a==a2)
	{
		cout<<1;
	}
	else
	{
		cout<<0000;
		return 0;
	}
	
	b0[0]=(int)(b[0]);
	b1[0]=(int)(b2[0]);
	b0[1]=(int)(b[1]);
	b1[1]=(int)(b2[1]);
	
	if(b0[0]==b1[0]&&b0[1]==b1[1])
	{
		cout<<1;
	}
	else
	{
		cout<<000;
		return 0;
	}
	
	
	if(b[2]>'C'&&b2[2]>'C'||b[2]<'D'&&b2[2]<'D')
	{
		cout<<1;
	}
	else
	{
		cout<<00;
		return 0;
	}
	
	if(b[2]>'c'&&b2[2]>'c')
	{
		cout<<1;
	}
	else if(b[2]=='B'||b2[2]=='B')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
