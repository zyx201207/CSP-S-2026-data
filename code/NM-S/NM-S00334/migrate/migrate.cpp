#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000010];
pair<long long,long long>f[2000010];
vector<long long>a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(long long q=1;q<=t;q++){
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			a[i].clear();
		}
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			for(long long j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d){
					a[j].push_back(i);
				}else{
					break;
				}
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				f[j]={1e18+7,0};
			}
			f[i]={0,1};
			for(long long j=i;j<=n;j++){
				long long l=a[j].size();
				for(long long k=0;k<l;k++){
					if(f[a[j][k]].first>f[j].first+1){
						f[a[j][k]].first=f[j].first+1;
						f[a[j][k]].second=f[j].second;
					}else if(f[a[j][k]].first==f[j].first+1){
						f[a[j][k]].second+=f[j].second;
					}
				}
			}
			for(long long j=i;j<=n;j++){
				if(f[j].second==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
