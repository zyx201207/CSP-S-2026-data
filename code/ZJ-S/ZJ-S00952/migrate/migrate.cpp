#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+7;
ll c,T;
ll n,d;
ll a[N];
ll cnt[N];
ll dis[N];
ll ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<=n;j++){
			dis[j]=0;
			for(int i=j+1;i<=n;i++){
				if(a[i]-d>a[i-1]) continue;
				int st=lower_bound(a+1,a+n+1,a[i]-d)-a;
				for(int k=max(j,st);k<i;k++){
					if(dis[k]+1==dis[i]){
						cnt[i]++;
					}
					else if(dis[k]+1<dis[i]){
						dis[i]=dis[k]+1;
						cnt[i]=1;
					}
				}
			}
			for(int i=2;i<=n;i++){
				if(cnt[i]==2){
					ans++;
				}
				cnt[i]=0;
			}			
		}
		cout<<ans<<'\n';
	}
	return 0;
}

