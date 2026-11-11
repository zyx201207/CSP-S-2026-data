#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,a[N],b[N],s[N],mx;
long long m,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) 
	{
		s[i]=s[i-1]+a[i]-a[i-1];
	}
	int l=1,r=2;
	sum=a[2]-a[1];
	while(r<=n)
	{
		if(sum<=m) 
		{
			mx=max(r-l+1,mx);
			sum+=(s[r+1]-s[r])*(r+1-l);
			r++;
		}
		else 
		{
			sum-=s[r]-s[l];
			l++;
		}
	}
	cout<<mx<<endl;
	return 0;
}
