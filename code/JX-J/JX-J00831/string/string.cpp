#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long len,ans;
long long sum[N],num[N];
char a[N];
bool pan(long long a,long long b,long long c)
{
	if(c%2) return a<c/2 && b>c/2+1;
	return a<=c/2 && b>=c/2+1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	sum[1]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>a[i];
		sum[i+1]=sum[i]+num[i];
		len+=num[i];
	}
	int l=0,r=n;
	long long ll=0,rr=len+1;
	while(pan(ll,rr,len))
	{
		long long pl,pr=0;
		l++;
		if(ll+num[l]>len/2) pl=len/2-ll;
		else pl=num[l];
		ll+=pl;
		while(pr<pl)
		{
			if(pr+(rr-sum[r])>pl)
			{
				if(a[r]!=a[l]) ans+=pl-pr;
				rr-=pl-pr;
				pr=pl;
			}
			else 
			{
				pr+=rr-sum[r];
				if(a[r]!=a[l]) ans+=rr-sum[r];
				rr=sum[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
