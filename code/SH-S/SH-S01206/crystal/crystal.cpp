#include<iostream> 
#include<algorithm>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, ans=1, cnt=0, m=0, cnt1=0;
	cin >> n >> m;
	long long a[n+10] , b[n+10];
	cin >> a[1] >> a[2];
	int num= a[2] - a[1];
	int num1=a[1] - a[2];
	if(a[1] == 1 && a[2] == 2)cnt += 2;
	for(int i = 3; i <= n; i++)
	{
		cin>> a[i];
		if(a[i] == i) cnt++;
		if(a[i] - a[i-1] == num || a[i-1] - a[i]==num1 || a[i-1] - a[i]==num || a[i] - a[i-1] == num1) cnt1++;
	}
	if(cnt == n)
	{
		for(int i = 1 ; i <= n; i++)
		{
			m = m-ans;
			if(m >= 0)
			{
				ans=ans+1;
			}
			else
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(cnt1 == n-1)
	{
		for(int i=1;i<=n;i++)
		{
			m=m-ans*num;
			if(m>=0)
			{
				ans=ans+1;
			}
			else
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}	
	
	sort(a+0,a+n);
	cnt=0;
	
	for(int i=1;i<=n-1;i++)
	{
		b[i]=a[i+1]-a[i];
		if(b[i]>m)
		{
			cnt++;
		}
	}
	
	if(cnt==n-1)
	{
		cout<<1;
		return 0;
	}
	
	int q=0,ans1=0;
	for(int i=1;i<=n;i++)
	{
		q = m;
		ans1 = 1;
		for(int j=i ;j <= n; j++)
		{
			q = q-ans1*b[j];
			if(q >= 0)
			{
				ans1 = ans1+1;
			}
			else
			{
				break;
			}
		}
		if(ans1 > ans)
		{
			ans = ans1;
		}
	}
	cout<<ans;
	return 0;
}
