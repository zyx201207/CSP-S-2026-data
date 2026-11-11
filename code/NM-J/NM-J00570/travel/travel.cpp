#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,c_2,s_1,s_2;
	long long r[3]={0},x[3]={0};
    cin>>c_1>>s_1>>c_2>>s_2;
    for(int i=0;i<3;i++)
    {
		r[i]=s_1[i]-'0';
		x[i]=s_2[i]-'0';
	}
    if(c_1==c_2)
    {
	     cout<<"1";
	}
	else
	cout<<"0";
	for(int i=0;i<2;i++)
	{
		if(r[i]==x[i])
		{
			cout<<"1";
		}
		else
		cout<<"0";
	}
	if(r[3]!='C')
	{
	     cout<<"1";
	}
	else
	{
	     cout<<"0";
    }
	if(abs(r-x==1))
	{
		 cout<<"1";
	}
	else
	cout<<"0";
	return 0;
}
		

