#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int c,t,n,d,x[N],l[N],r[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			l[i]=r[i]=0;
		}
		int ll=1,rr=1;
		for(int i=1;i<=n;i++){
			while(ll<=i&&x[i]-x[ll]>d) ll++;
			while(rr<=n&&x[rr]-x[i]<d) rr++;
			l[i]=ll,r[i]=rr; 
		}
//		cout<<r[1]<<" ";
		for(int i=1;i<=n;i++){
			int k=r[i]-1;
			int L=i,R=n;
			while(L<R){
				int mid=(L+R+1)>>1;
				if(l[mid]<k) L=mid;
				else R=mid-1;
			}
			if(l[L+1]==k){
//				cout<<l+1<<" ";
				for(int i=L+1;l[i]==k;i++){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
