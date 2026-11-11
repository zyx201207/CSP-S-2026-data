#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	long long m;
	long long a[200005];
	cin >> n >> m;
	for(long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int k;
    for (int i = 0; i < n-1; i++)
	{
	    for (int j = i+1; j < n; j++)
        {
            if(a[j] > a[i])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
	}
	long long b = a[m-1];
	for(long long i = m-1; i >= 0; i--)
	{
		b = b & a[m];
	}
	cout << b;
	return 0;
}
