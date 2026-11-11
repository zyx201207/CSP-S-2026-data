#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int cnt[64],n,m;
int maxa=0;
void s1(int a)
{
	int w=0;
	while(a!=0)
	{
		w++;
		cnt[w]+=(a%2);
		a=(a>>1);
	}
}
int ls;
void cq(int a)
{
	int w=0;
	while(a)
	{
		w++;
		if(cnt[w]-(a%2)==m) ls+=(1<<w);
		a=(a>>1);
	}
}
int a[200005];
int maxn;
void bl(int i2,int need,int ans)
{
	if(i2>n) return ;
	if(need==m)
	{
		maxn=max(maxn,ans);
		return ;
	}
	for(int i=i2+1; i<=n; i++)
	{
		if(i2!=0) bl(i,need+1,ans&a[i]);
		else bl(i,need+1,a[i]);
	}
}
bool jy(int x)
{
	while(x)
	{
		x=(x>>1);
		if(x%2==1 and x!=1) return false;
	}
	return true;
}
bool check()
{
	for(int i=1; i<=n; i++)
	{
		if(!jy(a[i]+1)) return false;
	}
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1)
	{
		int manx=0;
		for(int i=1; i<=n; i++)
		{
			manx=max(manx,a[i]);
		}
		cout<<manx;
		return 0;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=1; i<=n; i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				if((a[i]&a[j])>ans) ans=(a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n<=20)
	{
		bl(0,0,0);
		cout<<maxn;
		return 0;
	}
	else if(check())
	{
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n; i>=n-m; i--)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1)
	{
		int sum=a[1];
		for(int i=1; i<=n; i++)
		{
			s1(a[i]);
			sum=(sum&a[i]);
		}
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			ls=0;
			cq(a[i]);
			ans=max(ans,ls);
		}
		cout<<ans;
		return 0;
	}
	else if(maxa<4)
	{
		int cnt[4]= {0,0,0,0};
		for(int i=1; i<=n; i++)
		{
			cnt[a[i]]++;
		}
		if(cnt[3]>=m) cout<<3;
		else if(cnt[3]+cnt[2]>=m) cout<<2;
		else if(cnt[3]+cnt[2]+cnt[1]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	else
	{
		int js=1,cnt2=0;
		int ans=0;
		for(; js<n; js*=2) cnt2++;
		cnt2--;
		for(int i=cnt2; i>=1; i--)
		{
			if((1<<i)>=m) ans+=(1<<i);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

