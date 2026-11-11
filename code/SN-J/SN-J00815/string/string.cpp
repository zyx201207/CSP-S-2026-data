//SN-J00815 李雨轩 陕西延安中学
#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	long long num=0;
	while (l<=n)
	{
		if (a[l]>a[n])
		{
			if (c[l]==c[n])
			{
				a[l]-=a[n];
				a[n]=0;
				n--;
			}
			else
			{
				num+=a[n];
				a[l]-=a[n];
				a[n]=0;
				n--;
			}
		}
		else if (a[l]<a[n])
		{
			if (c[l]==c[n])
			{
				a[n]-=a[l];
				a[l]=0;
				l++;
			}
			else
			{
				num+=a[l];
				a[n]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else if (a[l]==a[n])
		{
			if (c[l]==c[n])
			{
				a[l]=0;
				a[n]=0;
				l++;
				n--;
			}
			else
			{
				num+=a[l];
				a[l]=0;
				a[n]=0;
				l++;
				n--;				
			}
		}
	}
	cout << num;
	return 0;
}
