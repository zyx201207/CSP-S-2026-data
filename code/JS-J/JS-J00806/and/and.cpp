#include <bits/stdc++.h>
using namespace std;
int n,k;	
int a[2000010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int ans = a[n];
	if(k==1)
	{
		cout << ans;
		return 0;
	}
	for(int i = n-1; i >= n-k+1; i--)
	{
		int ans1 = ans;
		ans1&=a[i];
		if(ans1==0) 
		{
			i++;
			continue;
		}
		ans&=a[i];
	}
	if(ans==0) cout << 1;
	else cout << ans;
	return 0;
}
