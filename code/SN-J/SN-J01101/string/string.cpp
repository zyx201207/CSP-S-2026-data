#include <bits/stdc++.h>
using namespace std;
struct hv{
	int m;
	char s;
};
hv p[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    long long cnt = 0;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> p[i].m >> p[i].s;
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = n - 1;j >= i;j--)
	    {
	        if (p[i].s != p[j].s)
	        {
	        	if (p[i].m == p[j].m)
	        	{
	        		cnt += p[i].m;
	        		break;
				}
				else
				{
					cnt += max(p[i].m,p[j].m) - min(p[i].m,p[j].m);
					break;
				}
			}
	    }
	}
	cout << cnt;
	return 0;
}
