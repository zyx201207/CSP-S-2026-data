#include<bits/stdc++.h>

using namespace std;

int n;
long long a[501000];
char b[501000];
bool c[501000]={0};

int main ()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	long long h1=1;
	long long h2=n;
	long long sum=0;
	while (1)
	{
		if((c[h1]==1&&a[h1]==0)||(c[h2]==1&&a[h2]==0))
		{
			break;
		}
		if(b[h1]!=b[h2])
		{
			if(a[h1] != a[h2])
			{
				if (a[h1] > a[h2])
				{
					sum+=a[h2];
					a[h1] -= a[h2];
					a[h2]=0;
					c[h2]=1;
					h2--;
					continue;
				}
				else
				{
					sum+=a[h1];
					a[h2]-=a[h1];
					a[h1]=0;
					c[h2]=1;
					h1++;
					continue;
				}
			}
			else
			{
				sum+=a[h1];
				a[h1]=0;
				a[h2]=0;
				c[h1]=1;
				c[h2]=1;
				h1++;
				h2--;
				continue;
			}
		}
		else
		{
			if(a[h1] != a[h2])
			{
				if (a[h1] > a[h2])
				{
					a[h1]-=a[h2];
					a[h2]=0;
					c[h2]=1;
					h2--;
					continue;
				}
				else
				{
					a[h2]-=a[h1];
					a[h1]=0;
					c[h1]=1;
					h1++;
					continue;
				}
			}
			else
			{
				a[h1]=0;
				a[h2]=0;
				c[h1]=1;
				c[h2]=1;
				h1++;
				h2--;
				continue;
			}	
		}
	}
	cout << sum;
	return 0;
}

