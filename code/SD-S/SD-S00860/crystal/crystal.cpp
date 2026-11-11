#include <bits/stdc++.h>
using namespace std;
//freopen
typedef long long ll;
const int N = 5e5+5;
long long int n,m,a[N],ans,ansp;
struct akt
{
	ll val,cost,profit=1;
}skl[N];
bool cmp(akt A,akt B)
{
	return A.profit>B.profit;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll pot1=1,pot2=1,pos=1,pot3=1,pot4=1;
	bool flag=1;
	while(pos<=n)
	{
		skl[pot2].val=a[pos];
		if(abs(pot2-pot1)>=1)
		{
			if(skl[pot1].profit*abs(skl[pot1].val-skl[pot2].val)+skl[pot1].cost+skl[pot2].cost<=m)
			{ 
				skl[pot2].val=max(skl[pot1].val,skl[pot2].val);
				skl[pot2].cost=skl[pot1].profit*abs(skl[pot1].val-skl[pot2].val)+skl[pot1].cost+skl[pot2].cost;
				skl[pot2].profit=skl[pot1].profit+skl[pot2].profit;
				pot1++;
				//ans++;
			}
			else
			{
				pot1++;
				pot3=pot1-1;
				//ans=max(ans,pot3);
				/*
				while(skl[pot1].profit*abs(skl[pot1].val-skl[pot2].val)+skl[pot1].cost+skl[pot2].cost-a[pot4]*(pot4-pot3+1)>m)pot4++;
				if(pot4==(n+1))break;
				skl[pot2].val=max(skl[pot1].val,skl[pot2].val);
				skl[pot2].cost=skl[pot1].profit*abs(skl[pot1].val-skl[pot2].val)+skl[pot1].cost+skl[pot2].cost-a[pot4]*(pot4-pot3+1);
				//printf("%lld ***<<<%lld\n",pot1,pot2);
				skl[pot2].profit=skl[pot1].profit+skl[pot2].profit-(pot4-pot3+1);
				pot3=pot4;
				pot1++;
				ans=max(ans,n-(pot2-pot3));
				*/
			}
			
		}
		//printf("%lld *** %lld *** %lld *** %lld ~~~ %lld ::::: %lld\n",pot2,skl[pot2].val,skl[pot2].cost,skl[pot2].profit,pot3,n-(pot2-pot3));
		if(pot2+1<=n)pot2++;
		else break;
		if(pos+1<=n)pos++;
		else break;
		
	}
	sort(skl+1,skl+1+n,cmp);
	
	printf("%lld",skl[1].profit);
	return 0;
}
//11 9 -2 -1 -1 0 1 2 2 6 7 9 10
