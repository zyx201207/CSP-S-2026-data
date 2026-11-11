#include<bits/stdc++.h>
#define int long long                                        
using namespace std;

const int N=5e5+10;

int rd()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int n,m,a[N],s[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<"\n"; 
	return 0;  
}
//Oct31==Dec25?










