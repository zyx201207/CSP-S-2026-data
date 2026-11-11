#include <bits/stdc++.h>
using namespace std;
long long s[100000005],a,b,c,sum;
int main()
{ 
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
    cin >> a;
    for (int i = 0; 1 < a; i++)
    {
    	cin >> b >> c;
    	for (int j = 0; j < b; j++)
    	{
    	    s[j] = c;	
		}
	}
	for (int m = 0, n = a-1; m < a, n >= 0; m++, n--)
	{
		if (s[m] != s[n])
		{
			sum++;
		}
	}
	cout << sum;
    return 0;
}