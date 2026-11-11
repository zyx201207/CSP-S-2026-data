#include <bits/stdc++.h>
using namespace std;

int c,t;
int n,d;
int z[2000010];
int b[2000010];
int a[2000010];
long long num,k;

int main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin >> c >> t;
	for (int asdf = 1;asdf <= t;asdf++)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> z[i];
			b[i] = z[i] + d;
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i;j <= n;j++)
			{
				if (b[i] < z[j])
				{
					b[i] = j - 1;
					k = 1;
				}
			}
			if (k == 0)
			{
				b[i] = n;
			}
			k = 0;
		}
		for(int i = n;i >= 1;i--)
		{
			a[i] = 0;
			if (b[i] < b[b[i] - 1])
			{
				a[i] += b[b[i] - 1] - b[i];
			}
			a[i] += a[b[i]];
			num +=  a[i];
		}
		cout << num << endl;
		num = 0;
	}
	
	return 0;
}
