#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010];
int pd()
{
	for(int i=2;i<n;i++)
	  if(a[i]-a[i-1]!=a[i+1]-a[i]) return 0;
	return 1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(pd())
	{
		m/=abs(a[2]-a[1]);
		for(int i=1;i<=n;i++)
		{
			m-=i;
			if(m<0)
			{
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}
	else
	{
		map<int,int> mp;
		int p=1,U=1,l=1,d=m,t=a[1];
		for(int i=2;i<=n;i++)
		{
			mp[a[i]]++;
			int K=t/p;
			if(K<=a[i]) m-=p*(a[i]-K),t+=p*(a[i]-K)+a[i];
			  else m-=K-a[i],t+=K;
			if(m>=0) U=max(U,++p);
			while(m<0&&l<=i)
			{
				p--;mp[a[l]]--;
				if(K==a[l]) 
				{
					if(mp[K]==0)
					{
						K=0;
						for(int j=l+1;j<=i;j++) K=max(K,a[j]);
						m+=p*(a[l]-K);
						t=p*K;
					} 
					else t-=K;
				}
				else m+=K-a[l],t-=K;
				l++;
			}
		}
		cout<<U<<endl;
	}
	return 0;
}
