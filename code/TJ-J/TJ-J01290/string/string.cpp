#include <bits/stdc++.h>
using namespace std;
int n,a[100000005],q,z,x;
string s[100000005],w;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> s[i];
		q+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;i<=a[i];j++)
		{
			w+=s[i];
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		if(w[i]==w[q+1-i])
		{
			z+=1;
		}
		else
		{
			x++; 
		}
	}
	if(z=n/2)
	{
		cout << "0";
	}
	else
	{
		cout << x; 
	}
	return 0;
}
 
