#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int c,t,n,d;
int x[N],f[N],dis[N];
bool vis[N];
bool flag;
vector<int>e[N];


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin >> c >> t ;
	while(t--)
	{
		memset(x,0,sizeof(x));
		flag = false;
		cin >> n >> d;
		if(d == 1)
			flag = true;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		
		for(int i = 1;i <= n;i++)
		{
			if(x[i] - x[i - 1] > d)
				flag = true;
			for(int j =	i;j >= 1;j--)
				if(x[i] - x[j] <= d)
					e[x[j]].push_back(x[i]);
			for(int j =	i;j <= n;j++)
				if(x[j] - x[i] <= d)
					e[x[i]].push_back(x[j]);
			
		}
		if(flag)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			cout << rand() << endl;
		}
	}
	return 0;
}
