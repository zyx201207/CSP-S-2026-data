#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,c;
    int sum=0,b,n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout); 
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
    	cin >> b;
    	cin >> c;
    	for(int j = 1;j<=b;j++)
    	{
    		
			a+=c;
		}
	}
    for(int i = 1;i<=n;i++)
    {
    	if(a[i]!=a[n-i-1])
    	{
    		sum++;
		}
	}
	cout << sum;
	return 0;
}

