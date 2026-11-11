#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b1,b2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	b[0] = 1;
	for(int i = 0;i < 30;i++){
		b[i] = b[i-1]*2;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		b1 = max(a[i],b1);
		b2 = min (a[i],b2);
	}
	sort(a,a+n);
	for(int i = 0;i * i < n;i++)
	{
		for(int i2 = 0;i2 < i;i2++)
		{
			if(a[i] == b[i2] -1)
			{
				sum = 1;
			}
		}
		if(sum == 1)
	}
	if (m == 1)
	{
		cout << b1;
		return 0;
	}if(m == 1){
		cout << 0;
	}
	return 0;
}
