#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL m,mm;
LL n;
LL ans = 0;
LL sum = 0;
LL a[500005];
LL maxa = LONG_LONG_MIN;
LL mina = LONG_LONG_MAX;
LL b[300];
bool flag = 1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(LL i = 1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxa = a[i]>maxa?a[i]:maxa;
		mina = a[i]<mina?a[i]:mina;
	}
	sort(a+1,a+n+1);
	//AB
	for(LL i = 2;i<=n-1;i++)
	{
		if(2*a[i]!=a[i+1]+a[i-1])
		{
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		LL d = a[2]-a[1];
		LL x = 0;
		ans = n;
		for(LL i = 1;i<=n;i++)
		{
			x = (((1+i)*i)/2)*d;
			if(x>m)
			{
				ans = i-1;
				break;
			}
		}
		cout << ans << endl;
		return 0;
	}
	//10-12
	if(mina>=-100&&maxa<=100&&m>1000000&&m<=100000000)
	{
		//cout << "10-12" << endl;
		for(LL i = 1;i<=n;i++)
		{
			b[a[i]+101]++;
		}
		for(LL i = 202;i>=2;i--)
		{
			LL t = 0,o = 0;
			LL ans1 = b[i];
			for(int j = i-1;j>=1;j--)
			{
				o = (i-j)*b[j];
				if(t+o<=m)
				{
					t += o;
					ans1+=b[j];
				}
				else
				{
					ans1 = ans1 + (m-t)/(i-j);
					ans = ans1>ans?ans1:ans;
					break;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	for(LL i = 1;i<=n;i++)
	{
		mm = m;
		ans = ans>=sum?ans:sum;
		sum = 0;
		for(LL j = i;j>=1;j--)
		{
			if(a[i]-a[j]<=mm)
			{
				mm-=a[i]-a[j];
				sum++;
			}
			else break;
		}
	}
	cout << ans << endl;
	return 0;
}

