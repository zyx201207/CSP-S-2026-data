#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1=0,s2=0,s3=0,s4=0;
	cin>>a>>x>>b>>y;
	if(a==b)
	{
		s1=1;
		string p="",d="";
		p=p+x[0]+x[1];
		d=d+y[0]+y[1];
		if(p==d)
		{
			s2=1;
			if(((x[2]>='A'&&x[2]<='C')&&(y[2]>='A'&&y[2]<='C'))||((x[2]>='D'&&x[2]<='F')&&(y[2]>='D'&&y[2]<='F')))
			{
				s3=1;
				if(abs(x[2]-y[2])==1)
				{
					s4=1;
					cout<<s1<<s2<<s3<<s4;
				}
				else
					cout<<s1<<s2<<s3<<s4;
			}
			else
			{
				cout<<s1<<s2<<s3<<s4;
				return 0;
			}
		}	
		else
		{
			cout<<s1<<s2<<s3<<s4;
			return 0;
		}
	}
	else
	{
		cout<<s1<<s2<<s3<<s4;
		return 0;
	}
	return 0;
}
