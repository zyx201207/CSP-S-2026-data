#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500010];
int v[500010];
int k;
struct zhan{
	int a[510];
	int t[510];
}z[30];
int x,y;
int num;
int h,asdf;

int main(){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> z[j].a[i] >> z[j].t[i];
			w[z[j].a[i]] += z[j].t[i];
			if (v[z[j].a[i]] != 0)
			{
				h = min(h,v[z[j].a[i]] + z[j].t[i]);
			}
			v[z[j].a[i]] += z[j].t[i];
		}
	}
	for(int i = 1;i <= q;i++)
	{
		num = 0;
		cin >> x >> y;
		num += w[x];
		num += w[y];
		for (int i = 1;i <= 20;i++)
		{
			if (z[i].a[1] == x)
			{
				asdf++;
			}
			else if(z[i].a[1] == y)
			{
				asdf++;
			}
		}
		if (asdf < 2)
		{
			num += h;
		}
		cout << num << endl;
	}
	
	
	return 0;
}
