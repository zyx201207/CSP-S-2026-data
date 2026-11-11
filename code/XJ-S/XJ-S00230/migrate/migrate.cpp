#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e6+5;
LL n,d,c,t,a[N],f[N],cnt[N],ans;
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++)f[j]=1e9,cnt[j]=0;
		f[i]=0;
		LL k=2;
		for(k;k<=n;k++){
			if(a[k]-a[i]<=d)f[k]=cnt[k]=1;
			else break;
		}
		for(int j=k;j<=n;j++){
			for(int p=j-1;p>=1;p--){
				if(a[j]-a[p]>d)break;
				if(f[j]>f[p]+1){
					f[j]=f[p]+1;
					cnt[j]=cnt[p];
				}
				else if(f[j]==f[p]+1)cnt[j]+=cnt[p];
			}
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
