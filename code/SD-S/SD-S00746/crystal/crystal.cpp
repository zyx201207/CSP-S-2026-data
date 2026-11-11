#include<bits/stdc++.h>
#define int long long
#define endl '\n'
const int N=5e5+10;
inline int read()
{
	int ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
using namespace std;
int n,m;
int a[N];
void solve()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int ans=1; 
	int k=m;
	int l=1;
	int l_=1;
	for(int i=2;i<=n;i++)
	{
		if((a[i]-a[i-1])*(l)<=k)
		{
			k-=(a[i]-a[i-1])*(l);
			l++;
		}
		else
		{
			while((a[i]-a[i-1])*(l)>k)
			{
				k+=a[i-1]-a[l_];
				l--;
				l_++;
			}
			k-=(a[i]-a[i-1])*(l);
			l++;
		}
		ans=max(ans,l);
		
	}
	ans=max(ans,l);
	cout<<ans<<endl;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	//T=read();
	while(T--) solve();
	return 0;
}
