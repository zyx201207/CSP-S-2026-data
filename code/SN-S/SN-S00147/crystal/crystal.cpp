#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define uint unsigned int 
#define endl '\n'

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while('0'>ch||ch>'9')
	{
		if(ch=='-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar(); 
	}
	return x * f;
}

const int inf = 1e18,N = 5e5 + 10;

int n,m,sum,a[N],s[N];

inline bool check(int r,int l)
{
	return (a[r] * (r - l + 1)) - (s[r] - s[l-1]) <= m;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	n = read(),m = read();
	for(int i = 1;i<=n;i++)
	{
		a[i] = read();
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++)
	{
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		int l = 1,r = i,ans = r;
		while(l<=r)
		{
			int mid = (l+r)>>1;
			if(check(i,mid))
			{
				ans = min(ans,mid),r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		sum = max(sum,i-ans+1);
	}
	cout<<sum<<endl;
	return 0;
}
//¹Ø×¢ Collapsarr ºÍ songjunhan004004 ß÷ 
