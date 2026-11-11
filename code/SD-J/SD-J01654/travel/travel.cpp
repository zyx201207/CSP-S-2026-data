#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
char s1[5],s2[5],c1[5],c2[5];
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++) cin>>s1[i];
	for(int i=1;i<=3;i++) cin>>s2[i];
	for(int i=1;i<=2;i++) cin>>c1[i];
	for(int i=1;i<=3;i++) cin>>c2[i];
	int t1=int(s1[1]*10)+int(s1[2]);
	int t2=int(c1[1]*10)+int(c1[2]);
	if(t1==t2)
	{
		cout<<1;
		t1=int(s2[1]*10)+int(s2[2]);
		t2=int(c2[1]*10)+int(c2[2]);
		if(t1==t2)
		{
			cout<<1;
			t1=(int)s2[3];
			t2=(int)c2[3];
			if(t1<=67&&t2<=67||t1>=68&&t2>=68)
			{
				cout<<1;
			}
			else 
			{
				cout<<0;
			}
			if(t1==67&&t2==68||t1==68&&t2==67)
			{
				cout<<0;
			}
			else if(t1-t2==1||t2-t1==1)
			{
				cout<<1;
			}
			else 
			{
				cout<<0;
			}
		}
		else
		{
			printf("00048 ");
		}
	}
	else 
	{
		printf("0000");
	}
	
	return 0;
 } 
