#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int n,m,a[N],cnt=0;
int cmp(int x,int y)
{
	if (x > y) return x>y;
	return x < y;

}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i = n/2+1; i <= n;i++)
	{ 
		if (a[i]<= a[n/2+1]&&m-(a[n/2+1]-a[i]) >= 0)
		{
			m-=(a[i]-a[n/2+1]);
			a[i]=a[n/2+1];
			cnt++;
		}
	} 
	if (m <= 0)
	{
		cout << cnt <<endl;
	}
	for (int i = 1; i <= n/2;i++)
	{
		if (m >= cnt*(a[i]-a[n/2+1]))
		{
			cnt++;
			m-=cnt*(a[i]-a[n/2+1]);
		}
	}
	cout <<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
