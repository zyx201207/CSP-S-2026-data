#include<bits/stdc++.h>
using namespace std;
long long my_n;
long long my_table[1000000],my_i[1000000],my_t,my_tong[1000000],my_p;
int main()
{	
	freopen("card.in","r",stdin);	freopen("card.out","w",stdout);
	cin>>my_n>>my_p;
	for(int my_j=1;my_j<=my_n;my_j++)
	{
		cin>>my_i[my_j];
	}
		for(int my_k=1;my_k<=my_n;my_k++)
		{
			for(int my_l=1;my_l<=my_n-my_k;my_l++)
			{
				for(int my_m=my_l;my_m<=my_n;my_m++)
				{
					if(my_table[my_m]==my_i[my_m-my_k]||my_table[my_m]==0)
					{
						my_table[my_m]=my_i[my_m-my_k];
						for(int my_o=my_m+1;my_o<=my_n;my_o++)
						{
							my_table[my_o]=0;
						}
					}
				}
			}
			for(int my_o=1;my_o<=my_p;my_o++)
			{
				if(my_table[my_o]>0)
				{
					my_tong[my_table[my_o]]++;
				}
			}
		}
	for(int my_k=1;my_k<=my_p;my_k++)
	{
		cout<<my_tong[my_k]<<" ";
	}
	return 0;
}
