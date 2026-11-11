#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 201000;
int n,sum,ans,k;
int a[N],c[N],dp[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout .tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for(int i = n;i >= 1;i--)
	{
		k++;
		if(c[n] != c[k])
		{
			if(a[i] == a[k])
			{
		    	c[n] = c[k];
		    	sum += a[n];
		    }
		}
		else if(a[n] == a[k])
		{
			if(a[i] != a[k])
			{
				a[n] = a[k];
				a[n - 1] -= a[k] - a[n];
				sum += (a[k] - a[n]) * 2;
			}
		}
	}
	cout << sum;
	return 0;
}
