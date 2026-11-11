#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,t,ans,to[5010],cnt[5010],sum[5010],can[5010];
ll a[2000010],d;
//vector<int> from[5010];
int main(){
    freopen("migrate1.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c<=10){
		for(int pq=1;pq<=t;pq++){
			scanf("%d%lld",&n,&d);
			ans=0;
			for(int i=1;i<=n;i++) sum[i]=cnt[i]=can[i]=0;
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			int r=1;
			for(int i=1;i<=n;i++){
				while(a[r+1]-a[i]<=d&&r<n) can[r]=i,r++;
				to[i]=r;
				can[r]=i;
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(to[i]-can[j]==1) cnt[j]++;
				}
			}
			for(int i=1;i<=n;i++){
				sum[i]=sum[i-1];
				if(cnt[i]==2) sum[i]++;
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					cout<<sum[j]<<" "<<sum[i]<<"\n";
					if(sum[j]-sum[i]==1) ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
    //while(t--){
		//scanf("%d%lld",&n,&d);
	//}
	return 0;
}
