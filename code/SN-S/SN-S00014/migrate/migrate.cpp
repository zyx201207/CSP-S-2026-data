#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e6;
int c,t,n,d;
int a[maxn];
long long ans=0;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			long long dy=a[2]-a[1];
			for(int j=i+2;j<=n;j++){
				if(a[j]-a[i]==3*d&&3*d<=dy){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
