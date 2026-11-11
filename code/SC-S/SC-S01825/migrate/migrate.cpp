#include <bits/stdc++.h>
using namespace std;
int main()
{
	preopen("migrate.in","r",stdin);
	preopen("migrate.out","w",stdout);
	int a,b;
	cin >>a>>b;
	for(int q=1;q<=b;q++)
	{
		int c,d,m[10000005],kk=0;
		cin >>c>>d;
		for(int j=1;j<=c;j++)
		{
			cin >>m[j];
		}
		for(int i=1;i<=c;i++){
			int k=0;
			for(int f=1;f<=d;i++)
			{
				for(int kl=d;kl>=1;kl--)
				{
					if(f+kl+i<=c)
					{
					if(f+kl+i==i+1+d)
					{
						k++;
					}
					}
				}
			if(k==2)
			{
				kk++;
			}
			}
		}
		cout<<kk<<endl;
	}
	return 0;		
}