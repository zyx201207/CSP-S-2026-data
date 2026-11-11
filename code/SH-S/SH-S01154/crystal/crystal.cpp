#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[50010],ans[50010],cnt,f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >>m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	cnt = 0;
	for(int c=1;c<=n;c++)
	{
		for (int f=0;f<=m;f++)
		{
			for(int i=1;i<=n;i++) 
			{
				a[i]+=f;
				cnt +=f;
			}
				
		}
		if (cnt <=m)
		{
			for(int i=1;i<=n;i++) 
			{
				if(a[i]=a[i+1])
				{
					ans[n]+=1;
				}
			}
		}
	}
	sort(ans+1,ans+1+n);
	cout <<ans[n];	
	return 0;
}

