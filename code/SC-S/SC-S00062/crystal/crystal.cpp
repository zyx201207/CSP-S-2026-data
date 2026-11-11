#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
const int N=500010;

int n;
ll m,a[N],s[N];

bool check(int mid,int i)
{
	ll res=1ll*(i-mid+1)*a[i];
	res-=s[i]-s[mid-1];
	return (res<=m);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		
		if(check(r,i)) ans=max(ans,i-r+1);
	}
	
	printf("%d\n",ans);
	return 0;
}