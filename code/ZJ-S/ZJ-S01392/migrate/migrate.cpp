#include<bits/stdc++.h>
using namespace std;
const int N=605;
typedef long long ll;
ll c,t,n,d,ans;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int pos=i,num=0;
				for(int k=i;k<=j;k++){
					if(a[k]-a[pos]>d&&k-pos==2) pos++;
					if(a[k]-a[pos]<=d&&k-pos==2&&k==j||a[k]-a[pos]<=d&&k<j&&k-pos==2&&a[k+1]-a[pos]>d){
						num++;
						pos=k;
					}
				}
				if(num==1) ans++;
			}
		}
		printf("%d\n",ans/2);
	}
	return 0;
}