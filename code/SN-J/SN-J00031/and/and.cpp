#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ma=INT_MIN,h=2147483647;
bool b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >>m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]>3)
		{
			b=1;
		}
		h=h&a[i];
		ma=max(ma,a[i]);
	}
	if(b==0)
	{
		sort(a+1,a+n+1);
		if(a[n-m+1]==1)
		{
			cout << 0;
		}
		else
		{
			cout << a[n-m+1];
		}
		return 0;
	}
	if(m==1)
	{
		cout << ma;
		return 0;
	}
	if(m==n)
	{
		cout << h;
		return 0;
	}
	if(m==2)
	{
		ma=INT_MIN;
		for(int i = 1;i<=n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout << ma;
		return 0;
	}
	sort(a+1,a+n+1);
	cout << a[n-m+1];
	return 0;
}
