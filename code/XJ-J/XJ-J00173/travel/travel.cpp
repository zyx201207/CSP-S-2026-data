#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	string c1,c2,s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
		int n1=0,n2=0;
		int flag=1;
		for(i=0;i<2;i++)
		{
			if(s1[i]!=s2[i]) flag=0;
		}
		if(flag==1) cout<<flag;
		else
		{
			cout<<"000";
			return 0;
		}
		if(s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'&&s1[2]<='E'&&s2[2]<='E')
		{
			cout<<1;
			char z1=s1[2],z2=s2[2];
			if(s1[2]>='D'&&s2[2]>='D'&&s1[2]<='E'&&s2[2]<='E')
			{
				cout<<1; 
			}
			else
			{
				if(z1>z2) swap(z1,z2);
			}
			if(z2==z1+1) cout<<1;
			else cout<<0;
		}
		else
		{
			cout<<"00";
		}
	}
	return 0;
 } 
