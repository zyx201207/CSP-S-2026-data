#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N],f[N];

int ans = 0,n,m;

void dfs(int k,int s,int t)
{
	
	if(k == m + 1)
	{
		ans = max(ans,s);
		return;
	}
	for(int i = t + 1 ; i <= n ; i++)
	{
		if(f[i] == 0)
		{
			f[i] = 1 ;
			
			dfs(k + 1,s & a[i],i);
			
			f[i] = 0 ;
		}
	}
}

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];	

	if(n <= 20)
	{
		dfs(1,((1 << 31)-1),0);
		
		cout << ans << '\n';
		return 0;
	}
	else if(m == 1)
	{
		sort(a + 1,a + 1 + n);
		
		cout << a[1] << '\n';
		return 0;
	}
	else if(m == n)
	{
		int t = a[1];
		for(int i = 2 ; i <= n ; i++)
			t = t & a[i];
			
		cout << t << '\n';
	}
	else if(m == 2)
	{
		int mx = 0;
		for(int i = 1 ; i <= n ; i++)
			for(int j = i + 1 ; j <= n ; j++)
				mx = max(mx,a[i] & a[j]);
				
		cout << mx << '\n';
	}
	else
	{
		sort(a + 1 ,a + 1 + n,cmp);
		
		int t = a[1];
		
		for(int i = 2 ; i <= m ; i++)
			t = t & a[i];
			
		cout << t << '\n'; 
	}
	return 0;
}
