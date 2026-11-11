#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
ll t,n,d,c,a[N],f[N],b[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll ans=0;
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
		}
		for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]>d&&i!=1) continue;
			for(int j=1;j<i;j++){
				b[i]=a[i]-a[j];
				if(a[j]-a[i]<=d){
					if(f[j]+1<b[i]){
						f[i]=f[j]+1;
					}
					else if(f[j]+1==b[i]){
						f[i]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(f[i]-f[j]==2&&a[i]-a[j]>d){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
