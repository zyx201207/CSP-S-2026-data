#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxn, maxn2, sum, box[200005], ans;
bool cmp(int x, int y)
{
	return x>y;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		box[a[i]]++;
	}
	sort(a+1, a+n+1, cmp);
	int ok=false;
	for(int i=1; i<=a[1]; i++)
	{
		if(box[a[i]]==m)
		{
			ans==a[i];
			ok=true;
		}
		maxn2=max(maxn2, ans);
	}
	if(ok){
		cout << maxn2;
		return 0;
	}
	sum=a[1];
	for(int i=2; i<=m; i++) sum=sum&a[i];
	cout << sum;
	return 0;
}
