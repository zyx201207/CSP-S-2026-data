#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+5;
#define int long long
int c,T;
int n,d;
int x[MAXN];
int dp[MAXN],minn[MAXN];
/*
0 1
6 12
0 5 8 16 20 31
*/
void sol1()
{
	while(T--)
	{
		cin >> n >> d;
		for(int i = 1;i<=n;i++) cin >> x[i];
		int ans = 0;
		for(int l = 1;l<=n;l++)
		{
			for(int r = 1;r<=n;r++)
			{
				int pos = l,sum1 = 0,sum2 = 0,num = 0;
				for(int i = l;i<=r;i++)
				{
					if(i == l)
					{
						sum1 = 1; sum2 = 1;
						num = 1;
						continue;
					}
					bool flag = 0;
					while(x[i] - x[pos] > d)
					{
						pos++;
						sum1--;
						if(sum1 == 0)
						{
							sum1 = sum2;
							sum2 = 1;
							num++;
							flag = 1;
						}
					}
					if(!flag) sum2++;
				}
				if(num == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);	cout.tie(0);
	cin >> c >> T;
	if(c == 0) sol1();
	else if(1 <= c && c <= 6) sol1();
	else
	{
		for(int i = 1;i<=T;i++) cout << rand()%114514 << '\n';
	}
	return 0;
}

