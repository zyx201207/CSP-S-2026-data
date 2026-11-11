#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],f[500050],ans,l,r,rm;
bool visl;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
		if(f[i]>m&&visl==0){l=i-1;visl=1;}
	}
	
	for(int i=2;i<=n;i++)
	{
	    r=i+l;
		if(r>n) break;
		while(( f[r]-f[i]-(a[r]-a[i])*(i-1) )<=m&&r<=n)
		{
			l++;
			r++;
		}
	}
	cout<<l;
	return 0;
}

