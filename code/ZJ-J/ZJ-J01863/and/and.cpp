#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
int t[40];
ll a[N];
void fj(int x)
{
	int w=0;
	while(x)
	{
		if(x&1)
			t[w]++;
		w++;
		x>>=1;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fj(a[i]);
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n-1)
	{
		sort(a+1,a+n+1);
		cout<<(a[2]&(-a[2]));
		return 0;
	}
	if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
			sum&=a[i];
		cout<<sum;
		return 0;
	}
	if(m==2)
	{
		ll maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxn=max(maxn,a[i]&a[j]);	
		cout<<maxn;
		return 0;	
	}
	sort(a+1,a+1+n,greater<int>());
//	for(int i=1;i<=n;i++)	
//		cout<<a[i]<<" ";
//	cout<<"\n";
	int l=0;
	for(int i=1;i<=40;i++)
		if(t[i]!=0)
			l++;
	while(t[l-1]==1)
	{
		l--;
		if(l==1)
			break;
	}
	ll sum=a[l-1];
	for(int i=l;i<m;i++)
		sum&=a[i];
	cout<<sum;
	return 0;
}
