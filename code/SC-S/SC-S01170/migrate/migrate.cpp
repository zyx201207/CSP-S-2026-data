#include<bits/stdc++.h>
#define pii pair<ll,ll>
using ll=long long;
using namespace std;
const int N=2e6+5;
ll a[N],cnt[15][15][15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T;
	cin>>c>>T;
	while(T--){
		ll n,d;
		cin>>n>>d;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int S=0;S<(1<<n);S++){
					if((S>>i)&1 and (S>>j)&1){
						int sum=0,lst=i,flag=1;
						for(int k=i;k<=j;k++){
							if(S>>k&1){
								if(a[k]-a[lst]>d){
									flag=0;
									break;
								}else{
									lst=k;
									sum++;
								}
							}
						}
						if(flag)cnt[i][j][sum]++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(cnt[i][j][k]!=0 and cnt[i][j][k]!=2){
						break;
					}else if(cnt[i][j][k]==2){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}