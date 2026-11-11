#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,xx,mx,c;
struct qjj{
	int gs,t;
}str[1000010];
bool f=1;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2) c=a[i]-a[i-1];
		else if(i!=1) 
		{
			if(a[i]-a[i-1]!=c)
				f=0;
		}
	}
//	cout<<n;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(a[i]==a[i-1]&&i!=1) str[xx].gs++;
		else str[++xx].t=i,str[xx].gs=1;
	for(int i=xx;i>=1;i--)
	{    	    
		ans=0;
		int cs=m;
		for(int j=i;j>=1;j--)	                                  
		{
			if(cs>(a[str[i].t]-a[str[j].t])*str[j].gs)
				ans+=str[j].gs,cs-=(a[str[i].t]-a[str[j].t])*str[j].gs;
			else
			{
				ans+=cs/(a[str[i].t]-a[str[j].t]);
				break;
			}
		}
		if(i==xx&&f==1)
		{
			cout<<ans;
			return 0;
		}	   
		mx=max(mx,ans);
	}             
	cout<<mx;
	return 0;
}