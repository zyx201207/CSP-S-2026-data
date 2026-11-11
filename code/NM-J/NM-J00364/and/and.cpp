#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans,j[20]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
bool ok1=1,ok2=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(ok2&&a[i]!=i-1) ok2=0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(ok2)
	{
		int k=1;
		while(j[k]-j[k-1]>=m) k++;
		if(a[k]<=n)
		{
			if(a[k-m+1]%2) a[k-m+1]-=1;
			cout<<a[k-m+1]%2;
		}
		else
		{
			ans=a[n];
			for(int i=1;i<=m+k;i++)
			{
				if(a[n-i]==2||a[n-i]==4||a[n-i]==8||a[n-i]==16||a[n-i]==32||a[n-i]==64||a[n-i]==128||a[n-i]==256||a[n-i]==512||a[n-i]==1024||a[n-i]==2048||a[n-i]==4096||a[n-i]==8192||a[n-i]==16384||a[n-i]==32768||a[n-i]==65536||a[n-i]==131072||a[n-i]==262144) 
					continue;
				ans=ans&a[n-i];
			}
			cout<<ans;
		}
		return 0;
	}
	cout<<a[n-m];
	return 0;
}
