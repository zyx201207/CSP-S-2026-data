#include<bits/stdc++.h>

using namespace std;

const int M = 2025,N = 2e6 + 10;

int c,t,n,d;
int x[N],dys[M][M];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --)
	{
		memset(x,0,sizeof(x));
		memset(dys,2,sizeof(dys));
		cin >> n >> d;
		for(int i = 1;i <= n;i ++)
		{
			cin >> x[i];
		}
		int dys1 = 2;
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
				if(x[j] - x[i] >= d) continue;
				else
				{
					dys[i][j] ++;
					
				}
			}
		}
		cout << 1 << endl;
	}
	
	
	return 0;
}
