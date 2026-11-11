#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n,b[200010],cnt = 0,c[200010];
    string s1,s2;   
    char a[200010]; 
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
    	c[i] = b[i];
    	cin >> b[i] >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= b[i]; j++)
		{
					s1 = s1 + a[i];
		}
	}
	for(int i = n,k = 1; i >= 1; i--)
	{
		k++;
		for(int j = b[i]; j >= 1; j--)
		{
					s2 = s2 + a[i];
					if(b[i] < c[k])
					{
						a[i] = a[k];
						cnt++;
					}
					
		}
	}
		cout << cnt;
		return 0;
}
