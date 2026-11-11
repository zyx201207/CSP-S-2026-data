#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans,num,sum,ca;
bool bo; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	ca=a[2]-a[1],bo=1;
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=ca){bo=0;break;}
	if(bo)
	{
		long long ss=0;
		for(int i=1;i<=n;i++)
		{
			if(ss+i*ca<=m) ss+=(long long)(i*ca);
			else
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		num=1,sum=0;
		for(int j=i-1;j>=1;j--)
		{
			if(sum+(a[i]-a[j])<=m)
			{
				sum+=(a[i]-a[j]);
				num++;
			}
			else break;
		}
		ans=max(ans,num);
	}
	cout << ans;
	return 0;
}
