#include<bits/stdc++.h>
using namespace std;
long long my_n,my_m,my_max=0,aaa,bbb,ccc,ddd,eee,fff,my_a[1000001];
bool my[7][7]=
{
	{0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0},
	{1,1,1,0,0,0,0},
	{1,1,1,1,0,0,0},
	{1,1,1,1,1,0,0},
	{1,1,1,1,1,1,0},
};
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>my_n>>my_m;
	for(int my_i=1;my_i<=my_n;my_i++)
	{
		cin>>my_a[my_i];
	}
	for(int aaa=1;aaa<=my_n;aaa++)
	{
		for(int bbb=aaa+my[1][my_m];bbb<=my_n;bbb++)
		{
			for(int ccc=bbb+my[2][my_m];ccc<=my_n;ccc++)
			{
				for(int ddd=ccc+my[3][my_m];ddd<=my_n;ddd++)
				{
					for(int eee=ddd+my[4][my_m];eee<=my_n;eee++)
					{
						for(int fff=eee+my[5][my_m];fff<=my_n;fff++)
						{
							if(aaa&bbb&ccc&ddd&eee&fff>=my_max)
							{
								my_max=aaa&bbb&ccc&ddd&eee&fff;
							}	
						}
					}
				}
			}
		}
	}
	cout<<my_max;
	return 0;
}
