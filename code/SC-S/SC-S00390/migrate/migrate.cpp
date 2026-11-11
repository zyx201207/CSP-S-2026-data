#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2000000+10;
int tid,T,n,pl[maxn],pr[maxn],ctl[maxn],ctr[maxn];
ll d,a[maxn],sl[maxn],sr[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>tid>>T;
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),ctl[i]=ctr[i]=0;
		for(int i=1;i<=n;i++){
			int l=1,r=i;
			while(l<r){
				int mid=(l+r)>>1;
				if(a[i]-a[mid]<=d) r=mid;
				else l=mid+1;
			}
			pl[i]=l; ctl[pl[i]]++; l=i; r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(a[mid]-a[i]<=d) l=mid;
				else r=mid-1;
			}
			pr[i]=l; ctr[pr[i]]++;
		}
		for(int i=1;i<=n;i++){
			sl[i]=ctr[i];
			if(pr[pl[i]]==i) sl[i]+=sl[pl[i]];
		}
		for(int i=n;i>=1;i--){
			sr[i]=ctl[i];
			if(pl[pr[i]]==i) sr[i]+=sr[pr[i]];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			int p1=pl[i],p2=i,p3=i+1,p4=pr[i+1];
			if(pr[p2]==p2 || p1==p2 || p3==p4) continue;
			ll s1=0,s2=0;
			if(pr[p1]==p3 && pl[p3]==p1) s1=sl[p3];
			else s1=ctr[p3]-(pr[p2]==p3);
			if(pr[p2]==p4 && pl[p4]==p2) s2=sr[p2];
			else s2=ctl[p2]-(pl[p3]==p2);
			ans+=s1*s2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}