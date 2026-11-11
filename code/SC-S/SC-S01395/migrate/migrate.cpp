#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> pll;
const int maxn=2e5+5;
const int inf=0x3f3f3f3f;
ll a[maxn];
ll dis[maxn];
ll ans[maxn];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		memset(dis,inf,sizeof(dis));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		dis[1]=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d){
					if(dis[j]>dis[i]+1){
						dis[j]=dis[i]+1;
						ans[j]++;
					}
					else if(dis[j]==dis[i]+1){
						ans[j]++;
					}
				}
				else break;
			}
		}
		int cnt=0;
		for(int i=2;i<=n;++i){
			if(ans[i]==2){
				++cnt;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}