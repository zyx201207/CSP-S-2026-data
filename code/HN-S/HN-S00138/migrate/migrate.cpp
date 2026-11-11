#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+5;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >>n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
//				cout << i<<' '<<x[i]+d<<endl;
				int pos=upper_bound(x+i+1,x+j+1,x[i]+d)-x-1;
				if(pos==j)
				{
					continue;
				}
				while(x[j]-x[pos]>d&&pos>i)
				{
					pos--;
				}
//				cout << pos<<endl;
				if(pos-i==2)
				{
//					cout << i<<' '<<j<<endl;
//					cout << i<<" "<<x[i]+d<<endl<<endl; 
					ans++;
				}
			}
		}
		cout << ans<<endl;
//		cout << endl;
	}
	return 0;
}
