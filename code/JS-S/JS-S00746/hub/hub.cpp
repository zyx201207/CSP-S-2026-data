#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,k,ui,vi;
		cin >> n >> k >> ui >> vi;
		for(int i = 1; i <= n; i++)
		{
			int mn = ui;
			if(vi < ui)
			{
				mn = vi;
			}
			cout << mn;
			int mx = vi;
			if(vi < ui)
			{
				mx = ui;
			}
			cout << mx;
		}
	}
	if(c == 0)
	{
		cout << 0;
	}
    cout << 1 << endl << 2 << endl;
	cout << 0 << endl;
	return 0;
}
