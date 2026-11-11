#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n];
	for(int i = 0;i < n;i ++) cin >> a[i];
	sort(a,a + n);
	int x = a[(n-1)/2];
	int s = 0;
	int i = 0,j = 0;
	while(j == m)
	{
		if(a[(n-1)/2 - i] <= x)
		{
			while(a[i] <= x)
			{
				a[i] ++;
				j++;
			}
		}
	}
	for(int i = 0;i < n;i ++)
	{
		if(a[i] == x)
		{
			s ++;
		}
	}
	cout << s + 2;
	return 0;
}
