#include<bits/stdc++.h>
using namespace std;
char aa[3];
int a,b,as,bs;
char bb[3];
bool c[6];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>as>>aa;
	cin>>b>>bs>>bb;
	c[1]=1;
	if(a!=b)
	{
		cout<<"0000";
		return 0; 
	}
	int o="C"-aa;
	int p="C"-bb;
	if(as==bs)	
	{
		c[2]=1;
		if(o<0&&p<0)
			c[3]=1;
		else if(o>0&&p>0)
			c[3]=1;
		if(aa-bb==1||aa-bb==-1)
			c[4]=1;
		for(int i=1;i<=4;i++)
			cout<<c[i];
	}
    else
		cout<<"1000";
	return 0;
}
