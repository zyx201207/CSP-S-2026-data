#include<bits/stdc++.h>
using namespace std;
long long my_num1=0,my_num2=0,my_num3=1,my_num21=0,my_num31=1;
long long my_n,my_js=0;
long long my_a[200004];
char my_c[200004];
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>my_n;
	for(int my_i=1;my_i<=my_n;my_i++)
	{
		cin>>my_a[my_i];
		cin>>my_c[my_i];
		my_num1=my_num1+my_a[my_i];
	}
	my_num31=my_n;
	for(long long my_i=1;my_i<=my_num1/2;my_i++)
	{
		my_num2++;
		my_num21++;
		if(my_num2>my_a[my_num3])
		{
			my_num2=0;
			my_num3++;
		}
		if(my_num21>my_a[my_num31])
		{
			my_num21=0;
			my_num31--;
		}
		
		if(my_c[my_num3]!=my_c[my_num31])
		{
			my_js++;
		}
	}
	cout<<my_js;
	return 0;
}
