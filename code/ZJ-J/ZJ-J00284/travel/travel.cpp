#include<bits/stdc++.h>
using namespace std;
string my_x,my_y,my_a,my_b;
int my_0a,my_0b;
bool my_f001[5];
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>my_a>>my_x>>my_b>>my_y;
	my_0a=(my_a[0]-48)*10+(my_a[1]-48);
	my_0b=(my_b[0]-48)*10+(my_b[1]-48);
	if(my_0a==my_0b)
	{
		my_f001[1]=1;
		if((my_x[0]-48)*10+(my_x[1]-48)==(my_y[0]-48)*10+(my_y[1]-48))
		{
			my_f001[2]=1;
			if((my_x[2]>='D')==(my_y[2]>='D'))
			{
				my_f001[3]=1;
				if((my_x[2]>='D'))
				{
					my_f001[4]=1;
				}
				else
				{
					if(((my_x[0]-48)*10-(my_y[1]-48)==1)||((my_x[0]-48)*10-(my_y[1]-48)==-1))my_f001[4]=1;
				}
			}
		}
	}
	cout<<my_f001[1]<<my_f001[2]<<my_f001[3]<<my_f001[4];
	return 0;
}
