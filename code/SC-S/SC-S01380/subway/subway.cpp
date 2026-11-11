#include <bits/stdc++.h>
using namespace std;
int x[200010];
bool est[200010];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int c, t; cin >> c >> t;
	while (t--)
	{
		int n, d, cnt = 0; cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
			est[x[i]] = true;
		}
		if (c == 11 || c == 12) {
			int dis = x[2]-x[1];
			int m = d/dis;
			cout << max(0, n-2*m+1) << '\n';
		} else if (c == 13 || c == 14) {
			int i = 1, j = 2;
			while (j <= n)
			{
			    while ((x[j]-x[i]) < d) j++;
		    	cnt ++; i++;
			}
			cout << cnt << '\n';
		} else {
	    	for (int i = 1; i <= n; i++) {
	    		int ss = x[i];
	    		int maxx = ss+2*d;
	    		int minn = ss+d;
	    		for (int j = i; j <= n; j++)
	    		{
	    			if ((x[j] > minn) && (x[j] < maxx)) {
	    				cnt ++;
	    			}
	    		}
	    	}
	    	cout << cnt << '\n';
		}
	}
}