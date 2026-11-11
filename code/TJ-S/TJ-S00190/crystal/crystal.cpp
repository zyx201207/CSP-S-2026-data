#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50005];
void solve1()
{
	sort(a+1,a+n+1);
	int i=1;
	long long chazhi=a[2]-a[1],num=1;
	while(m>0&&num<n)
	{
		if(m>chazhi*i)
		{
			m-=chazhi*i;
			num++;
			i++;
		}
		else
		{
			break;
		}
	}
	cout<<num;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>5000)
	{
		solve1();
		return 0;
	}
	else
	{
		long long cnt=1;
		sort(a+1,a+n+1);
		while(m>0&&m<n)
		{
			for(int i=1;i<n;i++)
			{
				m-=a[i+1]-a[i];
				cnt++;
			} 
			
		}
		cout<<cnt;
	}
	
	return 0;
} 
