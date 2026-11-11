#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],w[N] ,sum=0,sum3 =INT_MAX,c = 32,t,sum1,sum2;
bool f[N] = {};
bool b[N][33];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	t = n;
	for(int i = 1;i <= n;i++)//求二进制
	{
		cin>>a[i];
		int aa=a[i];
		int j = 0,k = 1;
		while(int(pow(2,j+1))<=a[i])
		{
			j++;
		}
		while(k<=j)
		{
			b[i][j-k+1] = aa%2;
			aa/=2;
			k++;
		}
		w[i] =j;
	}
	while(sum>= m)//找符合的c
	{
		sum = 0;
		
		for(int i = 1;i <= n;i++)
		{
			if(w[i]>= c)
			{
				sum++;
			}
		}
		c--;
	}
	while(t >m)
	{
		sum1=0;
		sum2=0;
		for(int i = 1;i <= n;i++)
		{
			if(f[i]!=1)
			{
				if(b[i][c]==1)
					sum1++;
				else
				{
					sum2++;
				}
			}
		}
		if(sum1>=m)
		{
			for(int i = 1;i <= n;i++)
			{
				if(b[i][c]==0)
				{
					f[i] = 1;
				}
			}
			t-=sum2;
			if(sum1==m)
			{
				break;
			}
		}
		c--;
	}
	for(int i = 1;i <= n;i++)
	{
		if(f[i]==0)
		{
			sum3=sum3&a[i];
		}
	}
	cout<<sum3;
}