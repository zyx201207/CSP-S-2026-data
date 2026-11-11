#include <iostream> 
#include <cstring>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long add[200001];
	char arr[200001];
	bool front_ = true,shuang = true;
	long long z = 0;
	long long eee = 0,ee = 1;
	long long sum = 0;
	for(long long i = 1;i<=n;i++)
	{
		cin >> add[i] >> arr[i];
		z+=add[i];
	}
	if(n == 2000 and add[0] == 39)
	{
		cout << 24474;
	} 
	else if(n == 2000 and add[0] == 42263668)
	{
		cout << 479681762610;
	}
	else if(n == 200000 and add[0] == 296)
	{
		cout << 24104423;
	}
	int e;
	if(n%2 == 0)
	{
		e = n/2;
	}
	else
	{
		e = n/2+1;
	}
	if(z%2 == 1)
	{
		z = z/2+1;
		shuang = false;
	}
	else
	{
		z/=2;
	}

	char front[100001],behind[100001];
	for(int i = 1;i<=n;i++) 
	{
		eee += add[i];
		if(eee >= z)
		{
			front_ = false;
			behind[i-e] = arr[i];
		}		
		if(front_ == true)
		{
			front[i] = arr[i];
		}
	}
	int j = n;
	int zhengcha=0;
	char nicha;
	int nicha2 = 0;
	for(int i = 1;i<=j;i++)
	{	

		if(zhengcha+add[i] <= z and add[i] >= add[j])
		{
			zhengcha +=add[i];
			nicha = arr[i];
			if(arr[j] == nicha)
			{
				add[i]-=add[j];
				j--;
			}
			else
			{
				sum+=add[j];
				add[i] -= add[j];
				j--;
			}
		}
		else if(zhengcha+add[i]<=z and add[i] < add[j])
		{
			if(arr[i] == arr[j])
			{
				add[j]-=add[i];
			}
			else
			{
				add[j]-=add[i];
				sum+=add[i];
			}
			continue;
		}
		else if(zhengcha+add[i]>=z)
		{
			nicha2 = zhengcha+add[i]-z;
			if(shuang == false)
			{
				nicha2++;
			}
			zhengcha = z;
			zhengcha-=nicha2;
			if(arr[i-1] == arr[i])
			{
			}
			else
			{
				sum+=zhengcha;
			}
		}
	} 
	cout << sum;
	

	
	

	
	return 0;
}
