#include <iostream>
#include <cstdio>
using namespace std;
struct s
{
	long long p;
	char v;
}q[200005];
long long n,l,r,num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	r = n;
	for (int i = 1;i <= n;i++)
	{
		cin >> q[i].p >> q[i].v;
	}
	while (l <= r)
	{
		if (q[l].v == q[r].v)
		{
			if (q[l].p < q[r].p)
			{
				q[r].p-=q[l].p;
				q[l].p = 0;
				l++; 
			}
			else if (q[l].p == q[r].p)
			{
				q[l].p = 0;
				q[r].p = 0;
				l++;
				r--; 
			}
			else
			{
				q[l].p -= q[r].p;
				q[r].p = 0;
				r--;
			}
		}
		else
		{
			if (q[l].p < q[r].p)
			{
				q[r].p-=q[l].p;
				num += q[l].p;
				q[l].p = 0;
				l++; 
			}
			else if (q[l].p == q[r].p)
			{
				num += q[l].p;
				q[l].p = 0;
				q[r].p = 0;
				l++;
				r--; 
			}
			else
			{
				num += q[r].p;
				q[l].p -= q[r].p;
				q[r].p = 0;
				r--;
			}
		}
	}
	cout << num;
	return 0;
}
