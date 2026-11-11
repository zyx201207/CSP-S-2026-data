#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+8;
ll n,m,a[N],sum[N],ans=-1;
ll read(){
	ll base=0,sign=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		base=(base<<3)+(base<<1)+ch-'0';
		ch=getchar();
	}
	return base*sign;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(a[1]<0)
	{
		for(ll i=1;i<=n;i++)
		{
			a[i]+=a[1];
		}
	}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=2,j,l,r,mid;i<=n;i++)
	{
		/*for(j=0;i-j>0;j++)
		{
			if(j*a[i]-sum[i-1]+sum[i-j-1]<=m) ans=max(ans,j+1);
		}*/
		l=0;r=i-1;
		while(l<r)
		{
			mid=(l+r+1)/2;
			//cout<<l<<" "<<r<<" "<<(mid*a[i]-sum[i-1]+sum[i-mid+1]<=m)<<endl;
			if(mid*a[i]-sum[i-1]+sum[i-mid-1]<=m) l=mid;
			else r=mid-1;
			
		}
		//cout<<l+1<<endl<<endl;
		ans=max(ans,l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
