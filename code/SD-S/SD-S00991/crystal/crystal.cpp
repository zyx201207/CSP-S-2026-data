#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],f[N];
bool che(int mid,int i)
{
	long long cnt=a[i]*(i-mid)-(f[i-1]-f[mid-1]);
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mx=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(che(mid,i))
			{
				r=mid-1;
			}else
			{
				l=mid+1;
			}
		}
		mx=max(i-r,mx);
	}
	cout<<mx;
	return 0;
}

