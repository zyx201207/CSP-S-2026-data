#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10, M=2e6+10;

int n, m;
bool f=true;
int t1[3010][5010];
int leen[3010], ans[3010], a[5010], leeen[3010];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	fst
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i-1]>a[i])
		{
			f=false;
		}
		t1[a[i]][++leen[a[i]]]=i;
		leeen[i]=leen[a[i]];
	}
	if(f)
	{
		for(int i=1; i<n; i++)
		{
			if(a[i]!=a[i+1])
			{
				ans[a[i]]=i;
			}
		}
		for(int i=1; i<m; i++)
		{
			cout << ans[i] << " ";
		}
		cout << n;
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		int t=leeen[i];
		for(int j=i; j<=n; j++)
		{
			t=leeen[j];
			if(t1[a[j]][t+1]!=0)
			{
				j=t1[a[j]][t+1]-1;
			}
			else
			{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout << ans[i] << " "; 
	}
	return 0;
}

