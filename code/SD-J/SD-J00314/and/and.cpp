#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010],b[200010];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	int ans=0;
	if(m==n)
	{
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1)
	{
		sort(b+1,b+1+n,cmp);
		cout<<b[1]<<'\n';
		return 0; 
	}
	if(m==2)
	{
		int maxx=INT_MIN;
		for(int i=1;i<n;i++)
		 for(int j=i+1;j<=n;j++)
		 {
		 	maxx=max(maxx,a[i]&b[j]);
		 }
		cout<<maxx<<'\n';
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m]<<endl;
	return 0;
}

