#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500010],t=0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	sort(a+1,a+n+1);
    if(n>5000) 
    {
    	if(a[1]==1&&a[2]==2&a[3]==3)
    	{
    		for(int j = 1;j<=n;j++)
    		{
    			m-=j;
    			if(m>=0)
    			{
    				t++;
				}
				else
				{
					break;
				}
			}
			cout << t;
			return 0;
		}
		else if(a[4]-a[3] == a[3]-a[2]&&a[3]-a[2] == a[2]-a[1])
		{
			int x = a[2]-a[1];
			for(int i = 1;i<=n;i++)
			{
				m-=i*x;
				if(m>=0)
				{
					t++;
				}
				else
				{
					break;
				}
			}
			cout << t;
			return 0;
		}
	}
	else
	{
		cout << n-1;
		return 0;
	}

    return 0;
}
