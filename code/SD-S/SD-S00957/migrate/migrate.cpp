#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ans,minn,l,tu,br;
void f(int u,int v,int step){
	if(u==v){
		if(minn==step){
			l++;
		}else{
			l=1;
			minn=step;
		}
		return;
	}
	if(step>=minn){
		br=1;
		return;
	}
	int L=u,R=v,mid;
	while(L<R){
		mid=(L+R)/2;
		if(a[mid]-a[u]>=d){
			R=mid-1;
		}else{
			L=mid+1;
		}
	}
	while(a[L+1]-a[u]<=d&&L<v){
		L++;
	}
	if(a[L+1]-a[L]>d&&L<v){
		tu=1;
		return;
	}
	for(int i=L;i>=u;i--){
		f(i,v,step+1);
		if(tu)return;
		if(br){
			br=0;
			return;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			for(int j=1;j<i-2;j++){
				br=0;
				tu=0;
				minn=1e18;
				l=0;
				f(j,i,0);
				if(l==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
