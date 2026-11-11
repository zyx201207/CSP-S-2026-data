#include<bits/stdc++.h>
using namespace std;

long long n,m,sum,num,ans;
long long a[500100];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<= n;i++)
    {
    	cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if(n == 1)
	{
	    cout << 1;	
	    return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n; j++)
		{
			if(a[i] - a[j] >= 0)
			{
				num++;
				sum += a[i] - a[j];
			}
		}
		if(sum <= m)
		{
			ans = max(num,ans);
		}
		num = 0;
		sum = 0;
	}
	cout << ans << endl;
    return 0;
}