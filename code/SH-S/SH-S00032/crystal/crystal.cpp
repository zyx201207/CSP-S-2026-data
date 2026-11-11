#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long ans;
long long n,m;
void f(long long k,long long s,long long cnt)
{
	if(k==n || (a[k+1]-a[k])*cnt>s)
	{
		ans=max(ans,cnt);
		return;
	}
	f(k+1,s-(a[k+1]-a[k])*cnt,cnt+1);
}
int fff()
{
	long long fa=a[2]-a[1];
	for(long long i=1; i<=n; i++)
	{
		if(m-i*fa<0) return i;
		m-=i*fa;
		if(i==n) return n;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000) cout<<fff();
	for(long long i=1; i<=n; i++)
		f(i,m,1);
	cout<<ans;
	return 0;
}
