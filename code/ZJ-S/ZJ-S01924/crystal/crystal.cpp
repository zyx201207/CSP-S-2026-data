#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m;
ll a[N],s[N];
bool f=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>100||a[i]<-100)
			f=0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--)
		s[i]=a[i]-a[i-1];
	bool b=0;
	for(int i=2;i<n;i++)	
		if(s[i]!=s[i+1])
			b=1;
	s[1]=0;
	if(n<=5000)
	{
		int maxn=0;
//		for(int i=1;i<=n;i++)
//			cout<<s[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=n;i++)
		{
			ll sum=0;
			for(int j=i;j<=n;j++)
			{
//				cout<<"i "<<i<<"\n";
				sum+=s[j]*(j-i+1);
//				cout<<sum<<"\n";
				if(sum>m)	
				{
					maxn=max(maxn,j-i+1);
					break;
				}
			}		
		}
		cout<<maxn;
		return 0;
	}
	if(!b)
	{
		ll d=s[3];
		ll sum=0;
		ll x=1;
		while(sum<=m&&x<=n)
		{
			sum+=d*x+d/2;
			x++;
		}
		cout<<x-1;
		return 0;
	}
	if(f)
	{
		int l=a[1],r=a[n];
		int maxn=0,g=0;
		for(int x=l;x<=r;x++)
		{
			ll sum=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]>x)
				{
					g=j-1;
					break;
				}
				if(sum>m)
				{
					g=j;
					break;
				}
				sum+=x-a[j];
			}
			maxn=max(maxn,g);
		}
		cout<<maxn;
		return 0;
	}     
	cout<<n;
	return 0;
}