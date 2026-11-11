#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
map<long long,long long> ma;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,am,k=1,ans=0,s=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(ma[a[i]])
		{
			ma[a[i]]++;
			ans=max(ans,1ll*ma[a[i]]);
		}
		else
			ma[a[i]]=1;
	}
	sort(a+1,a+n+1);
	s=1;
	am=m;
	for(int i=2;i<=n;i++)
	{
		if(m<(a[i]-a[i-1])*(i-k) && a[i]-a[i-1]>am-m)
		{
			m=am;
			k=i;
			s=1;
			continue;
		}
		while(m<(a[i]-a[i-1])*(i-k) && k<i-1)
		{
			m=m+a[i]-a[k];
			k++;
			s--;
		}
		m=m-(a[i]-a[i-1])*(i-k);
		s++;
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}