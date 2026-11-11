#include<bits/stdc++.h>
using namespace std;
string my_c1,my_c2,my_s1,my_s2;
char my_r[10],my_x[10];
char my_abc1(int my_rr,int my_xx)
{
	if(my_rr=='A')
	{
		if(my_xx=='B'||my_xx=='C')
		{
			return 1;
		}
	}
	if(my_rr=='B')
	{
		if(my_xx=='A'||my_xx=='C')
		{
			return 1;
		}
	}
	if(my_rr=='C')
	{
		if(my_xx=='A'||my_xx=='B')
		{
			return 1;
		}
	}
	if(my_rr=='D')
	{
		if(my_xx=='E')
		{
			return 1;
		}
	}
	if(my_rr=='E')
	{
		if(my_xx=='D')
		{
			return 1;
		}
	}
	return 0;
}
char my_abc2(int my_rr,int my_xx)
{
	if(my_rr=='B'||my_rr=='D'||my_rr=='E')
	{
		return 1;
	}
	if(my_rr=='A'||my_rr=='C')
	{
		if(my_xx=='B')
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>my_c1>>my_c2>>my_s1>>my_s2;
	for(int my_i=1;my_i<=2;my_i++)
	{
		my_r[my_i]=my_c1[my_i-1];
		my_x[my_i]=my_s1[my_i-1];
	}
	for(int my_i=3;my_i<=5;my_i++)
	{
		my_r[my_i]=my_c2[my_i-3];
		my_x[my_i]=my_s2[my_i-3];
	}
	if(my_r[1]==my_x[1]&&my_r[2]==my_x[2])
	{
		cout<<"1";
		if(my_r[3]==my_x[3]&&my_r[4]==my_x[4])
		{
			cout<<"1";
			if(my_abc1(my_r[5],my_x[5]))
			{
				cout<<"1";
				if(my_abc2(my_r[5],my_x[5]))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
