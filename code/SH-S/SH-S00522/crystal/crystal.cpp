#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long ansa[500005];
int n;
long long m;
int maxn = 0;
void kuosan(int nn)
{
	
	//memset(ansa,0,sizeof(ansa));
	for(int i = 1; i <= nn; i++)
	{
		ansa[i] =abs(a[i]-a[nn]); 
	}
	long long cnt = 0;
	int ans = 1;
	int l=nn-1;
	while(cnt <= m)
	{
		if(l >= 1)
		{
			if(cnt+ansa[l]<=m)
			{
				cnt += ansa[l];
				l--;
				ans++;
				
				
			}
			else
			{
				maxn = max(maxn,ans);
				break;
			}
		}
		else
		{
			maxn = max(maxn,ans);
			break;
		}
	}
	
}
long long suan(long long ans,long long cha)
{
	long long num = 0;
	for(int i = 1; i <= ans; i++)
	{
		num+=i*cha; 
	}
	return num;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f=1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int n1 = a[i]-a[i-1],n2 = a[i-1]-a[i-2];
		if(i>=3&&n1!=n2) f =0;
	}
	sort(a+1,a+n+1);
	if(f)
	{
		long long cha = a[2]-a[1];
		long long c = cha;
		long long cnt = 0;
		long long ans = 1;
		while(cnt <= ans)
		{
			int ad = suan(ans,cha);
			if(cnt+ad<=m)
			{
				ans++;
			}
			else
			{
				break;
			} 
		}
		cout << ans;
		return 0;
	}
	if(n<=5000)
	{
		for(int i = 1; i <= n; i++)
		{
			kuosan(i);
		}
		cout << maxn;
		return 0;
	}
	
	return 0;
} 
