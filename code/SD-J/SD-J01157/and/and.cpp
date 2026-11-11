#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a > b;
}
int a[200011],n,m,ans,ans2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n-m+1;i++)
	{
		ans2 = a[i+m-1];
		if(ans2 < ans)
		{
			cout << ans;
			return 0;
		}
		for(int j = i;j < i+m;j++)
		{
			ans2 = ans2&a[j];
		}
		ans = ans2;
	}
	cout << ans;
	return 0;
 } 
