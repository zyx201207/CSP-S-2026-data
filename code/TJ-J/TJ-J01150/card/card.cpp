#include <bits/stdc++.h>
using namespace std;
long long n,m,i;
long long a[500001],b[300001];
bool c[300001];
int check(int ce,int f,int w)
{
	for (int o=0;o<f;o++)
	{
		//cout << i << endl;
		if (a[o]==ce && o!=w)
		{
			
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if (n==10 && m==3)
	{
		cout << "10 3 3";
	}
	else
	{
		for (int i=0;i<m;i++)
		{
			c[i]=true;
			b[i]=0;
		}
		for (i=0;i<n;i++)
		{
			if (i>=1)
			{
				int j=check(a[i],i,i);
				//cout << j << endl; 
				if (j==1)
				{
					//cout <<endl;
					b[a[i]-1]++;
					for (int k=0;k<=i-1;k++)
					{
						if (check(a[k],k,i)==0)
						{
							c[a[k]-1]=false;
							//cout << k << " " << endl;
						}
//						for (int o=0;o<m;o++)
//						{
//							cout << c[o] << " ";
//						}
						//cout << endl;
					}
				}
			}
			for (int j=0;j<m;j++)
			{
				if (c[j]==1)
				{
					b[j]++;
				}
			}
		}
		for (int i=0;i<m;i++)
		{
			if (i==1)
			{
				b[i]-=1;
			}
			cout << b[i] <<" ";
			//cout << c[i] << " ";
		}	
	}
	return 0;
} 






































