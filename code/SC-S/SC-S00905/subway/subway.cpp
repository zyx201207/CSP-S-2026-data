#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int c,n,m,d,q,w[N],x,y,k[505],tz;

struct node
{
	int l,id,t;
}a[505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[j].id >> a[j].t;
			a[j].l = i;
		}	
	}
	
	while(q--)
	{
		cin >> x >> y;
		tz = w[a[x].id] + w[a[y].id] + a[x].t + a[y].t;
		cout << tz << endl;
		
	}
	
	return 0;
}