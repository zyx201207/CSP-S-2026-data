#include<bits/stdc++.h>
using namespace std;
long long my_b[4];
int my_n,my_m;
long long my_a[200004];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>my_n>>my_m;
	for(int my_i=1;my_i<=my_n;my_i++)
	{
		cin>>my_a[my_i];
//		cout<<my_i;
		if(my_i=1)
		{
			my_b[1]=my_a[my_i];
			my_b[2]=my_a[my_i];
			my_b[3]=my_a[my_i];
//			cout<<"q";
		}
//		cout<<"a";
		if(my_a[my_i]>my_b[3])
		{
			my_b[3]=my_a[my_i];
//			cout<<"w";
			if(my_b[3]>my_b[2])
			{
//				cout<<"e";
				my_b[0]=my_b[2];
				my_b[2]=my_a[my_i];
				my_b[3]=my_b[0];
				if(my_b[2]>my_b[1])
				{
//					cout<<"r";
					my_b[0]=my_b[1];
					my_b[1]=my_a[my_i];
					my_b[2]=my_b[0];
				}
			}
		}
//		cout<<"s";
	}
	cout<<my_b[3];
	return 0;
}
