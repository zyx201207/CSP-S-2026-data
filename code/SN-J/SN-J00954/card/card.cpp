#include <bits\stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin >> n >> m;
	int an[n];
	for (int i=0;i<n;i++)
	{
		cin >> an[i];
	}
	int q[n]={};
	int w[m]={};
	for(int i=1;i<=n;i++)
	{
		for(int i_1=i-1;i_1<=n;i_1++)
		{
			q[i_1-i+1]=an[i_1];
		}
		for(int i_2=0;i_2<n-i+1;i_2++)
		{
			for(int i_3=0;i_3<n-i+1;i_3++)
			{
				if(q[i_2]==q[i_3])
				{
					for(int ii=i_2;ii<i_3;ii++)
					{
						q[i]=0;
					}
				}
			}
		}
		for(int ii=1;ii<=m;ii++)
		{
			for(int ii_=1;ii_<=n-i;ii_++)
			{
				if(q[ii_]==ii)
				{
					w[ii-1]++;
					break;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
		cout << w[i]+1 << ' ';
	return 0;
}
