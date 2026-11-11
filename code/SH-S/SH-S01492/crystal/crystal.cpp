#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxc=5e5+5;
int n,maxn;
ll m,p[maxc],pz[maxc],pf[maxc];
ll prez[maxc],pref[maxc];

int main()
{
	prez[1]=0;
	pref[1]=0;  
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	int zg=0,fg=0;
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		if(x>=0)
		{
			zg+=1;
			pz[zg]=x;
		}
		else
		{
			fg+=1;
			pf[fg]=x;
		}
	}
	
	sort(pf+1,pf+fg+1);
	sort(pz+1,pz+zg+1);
	for(int i=1;i<=fg;i++)
		p[i]=pf[i];
	for(int i=fg+1;i<=zg+fg;i++)
		p[i]= pz[i-fg];
//	特判	(全部相同)
	{
	bool flag=1; 
	for(int i=1;i<n;i++)
	{
		if(p[i]!=p[i+1])
		{	
			flag=0;
			break;
		}
	}
	
	if(flag==1)
	{
		printf("%d",n);
		return 0;
	}
	}
	for(int i=2;i<=n;i++)
		prez[i]=p[i]-p[i-1];
	for(int i=1;i<=n;i++)
	{
		ll sum=0;
		for(int j=i+1;j<=n;j++)
		{
			if(sum+(j-i)*prez[j]<=m)
			{
				sum+=(j-i)*prez[j];
				continue;
			}
			else
			{
				
				maxn=max(maxn,j-i);
				break;
			}
		}
	}
	
	printf("%d",maxn);
	return 0;
} 
