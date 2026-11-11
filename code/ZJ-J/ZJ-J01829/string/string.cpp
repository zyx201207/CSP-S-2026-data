#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long m,ans,l,r,sum[N],a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		m+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	//cout<<m<<endl;
	long long mid=(m+1)/2,pl,pr;
	if(m%2)
	{
		pl=pr=mid;
	}
	else
	{
		pl=mid;
		pr=mid+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i-1]<=pl&&pl<=sum[i]) l=i;
		if(sum[i-1]<=pr&&pr<=sum[i]) r=i;
	}
	//cout<<pl<<' '<<pr<<endl;
	if(l==r)
	{
		long long kl,kr;
		kl=pl-sum[l-1];
		kr=sum[l]-pr+1;
		if(pl==pr)
		{
			a[l]-=2*min(kl,kr)-1;
			if(kl==kr) l--,r++;
			else if(kl<kr) l--;
			else r++;
		}
		else
		{
			a[l]-=2*min(kl,kr);
			if(kl==kr) l--,r++;
			else if(kl<kr) l--;
			else r++;
		}
	}
	//cout<<a[l]<<' '<<a[r];
	//cout<<ans<<endl;
	while(l>=1&&r<=n)
	{
	//	cout<<l<<' '<<r<<endl;
		long long x=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=x;
		a[l]-=x;
		a[r]-=x;
		if(a[l]<=0) l--;
		if(a[r]<=0) r++;
		//cout<<ans<<endl;
		//if(ans<0) break;
	}
	//cout<<a[1]<<' '<<a[n]<<endl;
	cout<<ans;
	return 0;
}