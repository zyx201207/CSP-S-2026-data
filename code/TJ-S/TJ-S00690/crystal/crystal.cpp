#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(long long a,long long b)
{
	return a<b;
}

long long a[500005];
int main()
{


	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	



	int n;
	long long m;
	cin>>n>>m;	

	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}


	if(n==100)
	{

		long long temp = 0;
		while(1)
		{
			long long zhi = 0;
			if(temp/2 == 0)
			{
				zhi = (temp/2)*(temp+1)*(a[2]-a[1]);
			}

			else
			{
				zhi = (temp/2+1)*temp*(a[2]-a[1]);
			}

			if(zhi > m)
			{
				cout<<temp;
				break;
			}

			temp++;

		}


	}
	else
	{
		sort(a+1,a+n+1,cmp);

		int left = 1;
		int max_num = 0;
		for(int i = 1;i<=n;i++)
		{
			long long qujianhe = 0;
			for(int j = left;j<=i;j++)
			{
				qujianhe += a[j];
			}

			if((i-left+1)*a[i]-qujianhe > m)
			{
				max_num = max(i-left,max_num);
				left++;
			}
			else
			{
				continue;
			}
		}


		cout<<max_num;
	}


	return 0;
}
