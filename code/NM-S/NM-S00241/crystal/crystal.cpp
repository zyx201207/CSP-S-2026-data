#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
ll n,m;
ll a[N],aa[N];
priority_queue<int, vector<int>,greater<int> > q;
bool f(ll g)
     {
     	ll cnt=0;
     	for(ll j=1;j<=g;j++)
     	    cnt+=(a[g]-a[j]);
     	if(cnt<=m) return true;
			else return false;
	 }
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
	   {
	   scanf("%d",&aa[i]);
	   q.push(aa[i]);
		} 
	for(ll i=1;i<=n;i++)
	    {
	    	a[i]=q.top();
	    	q.pop();
		}
	ll l=1,r=n;
	while(l<=r) 
	{
		ll mid=(l+r)/2;
		if(f(mid)==true) l=mid+1; 
		    else  r=mid-1;
	}
	printf("%lld\n",r);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
//TYLOO JEE AAAWWWPPP TEAM SPIRIT D0NK
