#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct T
{
	int num;char c;
}a[N];
int n;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].num >> a[i].c;
	}
	int l=1,r=n;
	while(1)
	{
		if(l>=r)break;
		if(a[l].c==a[r].c)
		{
			if(a[l].num > a[r].num)
			{
				a[l].num-=a[r].num;a[r].num=0;
			}
			else
			{
				a[r].num-=a[l].num;a[l].num=0;
			}
			if(a[l].num == 0)l++;if(a[r].num == 0)r--;
		}
		else
		{
			if(a[l].num > a[r].num)
			{
				a[r].c = a[l].c;ans+=a[r].num;
			}
			else
			{
				a[l].c = a[r].c;ans+=a[l].num;
			}
		}
	}
	cout << ans;
}
