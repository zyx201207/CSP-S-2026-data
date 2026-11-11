#include<bits\stdc++.h> 
using namespace std;
long long a[200005];
long long maxn=-1000; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	long long ans=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans=ans&a[i]; 
	}
	if(m==n) cout<<ans;
	else if(m==1)
	{
		sort(a,a+n);
		cout<<a[n-1];
	}
	else if(m=n-1)
	{
		for(int i=0;i<n;i++)
		{
			maxn=max((ans^a[i]),maxn);
		}
	}
	else if(m=2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j) maxn=max((a[i]&a[j]),maxn);
			}
		}
	}
	return 0;
}
