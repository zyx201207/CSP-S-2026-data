#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10;
ll x[N];
ll f[N],cnt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			memset(f,0x3f,sizeof f);
			memset(cnt,0,sizeof cnt);
			cnt[i]=1;f[i]=0;
			for(int j=i;j<=n;j++){
				if(cnt[j]==2)ans++;
				for(int k=j+1;k<=n;k++){
					if(abs(x[k]-x[j])<=d){
						if(f[k]>f[j]+1ll){
							cnt[k]=cnt[j];
							f[k]=f[j]+1ll;
						}
						else if(f[k]==f[j]+1ll){
							cnt[k]+=cnt[j];
						}
					}
					else{
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}