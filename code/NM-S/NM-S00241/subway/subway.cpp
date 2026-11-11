#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+50;
ll c,n,m,d,q,w[N],k[N],x[N],y[N];
struct node{
	ll a[N],t[N];
}e[22];
struct node1{
    ll l[22],s[22];
}z[N];
bool f[N];
ll sum[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(ll i=1;i<=n;i++){
	    scanf("%lld",&k[i]);
        for(ll j=1;j<=k[i]-1;j+=2)
            {
			scanf("%lld%lld",&e[i].a[j],&e[i].t[j]);
			z[e[i].a[j]].l[i]=i;
			z[e[i].a[j]].s[i]=e[i].t[j];
			}
	}
	for(ll i=1;i<=n;i++)
	    scanf("%lld%lld",&x[i],&y[i]);
	for(ll i=1;i<=q;i++)
	    {
	    	ll cnt=0;
	    	memset(f,false,sizeof(f));
			cnt+=(w[x[i]]+w[y[i]]);
	    	for(ll j=1;j<=n;j++)
	    	    for(ll kk=1;kk<=k[j];kk++)
	    	        {
					
					if((e[j].a[kk]==x[i]))  
			            {
			                cnt+=e[j].t[kk];
			            }
			        if(e[j].a[kk]==y[i]) 
			            {
			                cnt+=e[j].t[kk];	
			            }
	    	        }
	    	for(ll j=x[i];j<=y[i];j++)
	    	    for(ll kk=1;kk<=m;kk++)
	    	        for(ll zm=1;zm<=m;zm++)
	    	        if((z[i].l[kk]!=z[i-1].l[kk])&&z[i].l[zm]==z[i-1].l[zm]) cnt+=z[i-1].s[zm];
	    	            else if((z[i].l[kk]==z[i-1].l[kk])) cnt+=z[i-1].s[kk];
	    	printf("%lld\n",cnt);
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
//TYLOO DANK1NG SSG-08 -> 头 VITALITY ZYW0O 
//TYLOO DANK1NG SSG-08  VITALITY FLAMEZ
//NAVI S1MPLE AAAWWWPPP G2 NIKO
//
//
//TYLOO ZERO AK47 FALCONS NIKO
//TYLOO ZERO AK47 FALCONS MONESY
//TYLOO ZERO AK47 FALCONS TESES
//TYLOO ZERO AK47 FALCONS KARRIGAN
//TYLOO ZERO AK47 FALCONS KIYOUSUKE
//FALCONS 13:8 FURIA
//FALCONS 13:8 FURIA
//FALCONS 13:8 FURIA
//FALCONS 3:0  FURIA
