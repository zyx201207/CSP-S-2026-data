#include<bits/stdc++.h>
using namespace std;

long long int n,a[200005],i,sum1,sum2,sum,same,p = 2,q;
char c[200005],c1,c2;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	q = n-1;
	for(i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	sum1 = a[1],sum2 = a[n];
	if(c[1] == c[n])
	{
		if(sum1 <= sum2) same += a[1];
		else same += a[n];
	}
	while(sum1 + sum2 < sum)
	{
		if(sum1 <= sum2)
		{
			sum1 += a[p];
			c1 = c[p];
			if(c1 == c2)
			{
				if(sum1 <= sum2) same += a[p];
				else same += sum2 - (sum1 - a[p]);
			}
			p++;
		}
		else
		{
			sum2 += a[q];
			c2 = c[q];
			if(c1 == c2)
			{
				if(sum2 <= sum1) same += a[q];
				else same += sum1 - (sum2 - a[q]);
			}
			q--;
		}
	}
	if(sum1 > sum/2) same += sum1-sum/2-1;
	if(sum2 > sum/2) same += sum2-sum/2-1;
	cout << sum/2-same;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
