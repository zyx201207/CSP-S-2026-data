#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin >> m >> n;
	int arr[m];
	double sum = 0;
	int e = 1;
	int num = 0,zhongdian;
	double min = 100000.0;
	long long num2 = 0;
	int sum2 = 0;
	for(int i = 1;i<=m;i++)
	{
		cin >> arr[i];
		sum+=arr[i]*1.0;
	}
	sum = sum/m*1.0;
	for(int i = 1;i<=m;i++)
	{
		if(abs(sum - arr[i]) < min)
		{
			min = abs(sum - arr[i]);
			zhongdian = arr[i];
		}
	}
	for(int i = 1;i<=m;i++)
	{
		if(zhongdian >= arr[i])
		{
			arr[e] = zhongdian - arr[e];
			e++;
		}
		else
		{
			continue;
		}
	}
	for(int i = 1;i<=e;i++)
	{
		for(int j = i;j<=e;j++)
		{
			if(arr[i] > arr[j])
			{
				swap(arr[i],arr[j]);
			}			
		}
	}
	for(int i = 1;i<=e;i++)
	{
		if(num2+arr[i] <= n)
		{
			num2+=arr[i];
			sum2++;
		}
	}
	cout << sum2;

	
	
	
	
	



	
	
	
	
	return 0;
} 
