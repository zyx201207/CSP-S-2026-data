#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int a[N],fa[N],jp[N];

int find(int x)
{
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T,n,d;
	cin>>c>>T;
	while(T--)
	{
		int sum = 0;
		cin>>n>>d;
		for(int i = 1 ; i <= n ; i++)cin>>a[i],jp[i] = 0,fa[i] = i;
		for(int i = n ; i >= 1 ; i--)
		{
			int l = upper_bound(a + i + 1,a + n + 1,a[i] + d) - a - 1;
			if(i != 1 && a[l] - a[i - 1] <= d)continue;
			if(l == i)continue;
			fa[i] = jp[i] = l;
		}
		for(int i = 1 ; i < n ; i++)
			for(int j = i + 1 ; j <= n ; j++)
			{
				int t = 0;
				for(int k = i ; k <= j && k ; k = jp[k])
				{
					if(k == j)break;
					t += (find(k - 1) == find(j));
				}	
				if(t > 1)t = 0;
				sum += t;
			}
		cout<<sum<<endl;
	}
	return 0;
 } 
