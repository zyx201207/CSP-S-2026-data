#include<bits/stdc++.h>
using namespace std;

long long n, a, pr,py,sp, ans;

struct plc{
	long long st;
	long long ed;
	long long l;
	char c;
};
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	plc p[n+5];
	a = 0;
	ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i].l;
		p[i].st = a;a += p[i].l-1;p[i].ed = a;a++;
		cin >> p[i].c;
	}
	if(1==1)
	{
		pr = 0;py = 1;
		sp = 0;
		while(n-py > pr)
		{
			if(p[pr].l>p[n-py].l)
			{
				if(p[pr].c != p[n-py].c)
				{
					ans += p[n-py].l;
				}
				py++;
				sp+=p[a-py].l;
				p[pr].l -= p[n-py+1].l;
			}
			else if(p[pr].l<p[n-py].l)
			{
				if(p[pr].c != p[n-py].c)
				{
					ans += p[pr].l;
				}
				pr++;
				sp+=p[pr].l;
				p[n-py].l -= p[pr-1].l;
			}
			else
			{
				if(p[pr].c != p[n-py].c)
				{
					ans += p[pr].l;
				}
				pr++;py++;
				sp+=p[pr].l;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
