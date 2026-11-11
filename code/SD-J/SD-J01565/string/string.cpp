#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],sum;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld %c",&a[i],&c[i]);
		sum+=a[i];
	}
	int mid=sum/2,l=0,r=n,id=1,ans=0;
	while(1){
		if(l+a[id]<=mid){
			l+=a[id];
			while(a[id]>0){
				if(a[id]>=a[r]){
					if(c[id]!=c[r]){
						ans+=a[r];
					}
					a[id]-=a[r];
					a[r]=0;
				}else{
					if(c[id]!=c[r]){
						ans+=a[id];
					}
					a[r]-=a[id];
					a[id]=0;
				}
				if(a[r]==0){
					r--;
				}
			}	
		}else{
			int u=mid-l;
			while(u>0){
				int v;
				if(r==id){
					v=a[r]-u;
				}else{
					v=a[r];
				}
				u-=v;
				if(c[id]!=c[r]){
					ans+=v;
				}
				r--;
			}
			break;
		}
		id++;
	}
	printf("%lld",ans);
	return 0;
}
