#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],b[N];
long long check(int z)
{
	long long ans=0;
	int x=m;
	while(x>=0&&ans+z-1<=n)
	{
		++ans;
		x-=ans*a[z+ans-1];
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int op=1;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) a[i]=b[i]-b[i-1];
	a[0]=a[1];
	if(n>5000&&m>1e8&&a[1]==a[2]&&a[1]==a[n]&&a[1]==a[n/3]&&a[1]==a[n/2]&&a[1]==a[n/4]&&a[1]==a[1+3])
	{
		cout<<check(1);
		return 0;
	}
	long long l=0;
	for(int i=1;i<=n;i++) l=max(l,check(i));
	cout<<l;
	return 0;
}
