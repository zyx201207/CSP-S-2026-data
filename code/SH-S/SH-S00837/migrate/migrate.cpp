#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000001],cnt;
bool check(int pnt){
	return a[pnt+1]-a[pnt]<=d&&a[pnt+2]-a[pnt]<=d&&a[pnt+3]-a[pnt]>d&&a[pnt+3]-a[pnt+2]<=d&&a[pnt+3]-a[pnt+1]<=d;
}signed main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		cnt=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n-3;i++){
			if(!check(i)) continue;
			int l=1,r=1,ans;
			for(int j=i-1;j>0;j--){
				if(!check(j)&&a[j+1]-a[j]<=d) l++;
				else break;
			}for(int j=i+4;j<=n;j++){
				if(!check(j-3)&&a[j]-a[j-1]<=d) r++;
			}ans=l*r;
			cnt+=ans;
		}printf("%lld\n",cnt);
	}return 0;
}
