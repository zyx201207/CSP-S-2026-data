#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %s",&a[i],&c[i]);
	}
	int l=1,r=n;
	int ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
				}else{
					l++;
					r--;
				}
			}
		}else{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
				}else{
					l++;
					r--;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

