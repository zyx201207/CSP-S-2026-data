#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<long long> b[35];
long long read() 
{
	long long ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') 
	{
		if(c=='-') 
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0') 
	{
		ans=ans*10+(c-'0');
		c=getchar();
	}
	return ans*f;
}
void chai(long long x) 
{
	int sum=0;
	long long cur=x;
	while(x) 
	{
		sum++;
		if(x%2==1) 
		{
			b[sum].push_back(cur);
		}
		x>>=1;
	}
}
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	if(m==1) 
	{
		long long maxa=-1;
		for(int i=1; i<=n; i++) 
		{
			a[i]=read();
		}
		for(int i=1; i<=n; i++) 
		{
			maxa=max(maxa,a[i]);
		}
		cout<<maxa<<endl;
		return 0;
	}
	if(m==2) 
	{
		for(int i=1; i<=n; i++) 
		{
			a[i]=read();
		}
		for(int i=1; i<n; i++) 
		{
			for(int j=i+1; j<=n; j++) 
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n)
	 {
		for(int i=1; i<=n; i++) 
		{
			a[i]=read();
		}
		ans=a[1];
		for(int i=2;i<=n;i++) 
		{
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1) 
	{
		long long mi=1e18;
		for(int i=1; i<=n; i++) 
		{
			a[i]=read();
			mi=min(mi,a[i]);
		}
		int zhi=1;
		for(int i=1; i<=n; i++) 
		{
			if(a[i]==mi&&zhi) 
			{
				zhi=0;
				continue;
			}
			if(ans==0) 
			{
				ans+=a[i];
			} 
			else 
			{
				ans=ans&a[i];
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		a[i]=read();
		chai(a[i]);
	}
	for(int i=30; i>=1; i--) 
	{
		ans<<=1;
		if(b[i].size()>=m) 
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
