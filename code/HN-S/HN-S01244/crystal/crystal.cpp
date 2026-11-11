#include<bits/stdc++.h>
using namespace std;
constexpr long long N=5e5,M=1e5,W=1e18;
long long n,m,a[N+5];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>n>>m;
	
	if(n==1) cout<<"1\n";
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	long long ans=0;
	
	{
		long long tot=0,lef=m;
		
		for(int i=n;i>=1;i--)
		{
			if(a[n]-a[i]<=lef) tot++,lef-=a[n]-a[i];
			else break;			
		}
		
		ans=tot;
		
		for(int i=n-1;i>=1;i--)
		{
			tot--;
			lef+=tot*(a[i+1]-a[i]);
			
			for(int j=i-tot;j>=1;j--)
			{
				if(a[i]-a[j]<=lef)	tot++,lef-=a[i]-a[j];
				else break;
			}
			
			ans=max(ans,tot);
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
//I love G.A.Cohen's <<WNS?>>.
//Why don't you have a try?
/*
5 8 
-3 -1 2 2 7
*/
