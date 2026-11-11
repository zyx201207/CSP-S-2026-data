#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010],ans,cnt[40],c[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;(1<<j)<=a[i];j++){
			if((a[i]>>j)&1){
				cnt[j]++;
			}
		}
	}
	for(int i=31;i>=0;i--){
		if(cnt[i]>=m){
			ans|=(1<<i);
			memset(cnt,0,sizeof(cnt));
			int l=0;
			for(int j=1;j<=n;j++){
				if((a[j]>>i)&1){
					c[++l]=a[j];
					for(int k=0;(1<<k)<=a[j];k++){
						if((a[j]>>k)&1){
							cnt[k]++;
						}
					}
				}
			}
			n=l;
			memcpy(a,c,sizeof(a));
		}
	}
	printf("%d",ans);
}
