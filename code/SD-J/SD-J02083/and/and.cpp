#include <bits/stdc++.h>
using namespace std;

long long a[2000005],num;

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a + n,cmp);
	for(int i = 1;i < m;i++)
	{
		num = a[i] & a[i - 1];
	}
	cout << num;
	return 0;
} 
