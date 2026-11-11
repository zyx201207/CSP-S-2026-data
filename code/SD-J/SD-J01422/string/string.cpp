#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5*3+10;
struct aaa{
	long long num;
	char c;
};
long long n;
aaa a[N];
long long l,r;
long long cl,cr;
char cc;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	l = 1;
	r = n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i].num >> a[i].c;
	}
	while(l<=r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].num<a[r].num)
			{
				a[r].num-=a[l].num;
				cc = a[r].c;
				l++;
			}
			else if(a[l].num==a[r].num)
			{
				l++;
				r--;
				cc = ' ';
			}
			else
			{
				a[l].num-=a[r].num;
				cc = a[l].c;
				r--;
			}
		}
		else
		{
			if(a[l].num<a[r].num)
			{
				ans+=a[l].num;
				a[r].num-=a[l].num;
				cc = a[r].c;
				l++;
			}
			else if(a[l].num==a[r].num)
			{
				ans+=a[l].num;
				l++;
				r--;
				cc = ' ';
			}
			else
			{
				ans+=a[r].num;
				a[l].num-=a[r].num;
				cc = a[l].c;
				r--;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
