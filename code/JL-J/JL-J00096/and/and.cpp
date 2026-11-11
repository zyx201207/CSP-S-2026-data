#include <cstdio>
#include <algorithm>
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		int maxn=-1e9;
		for(int i=1;i<=n;i++){
			maxn=std::max(maxn,a[i]);
		}
		printf("%d",maxn);
		return 0;
	}else if(m==2){
		int maxn=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxn=std::max(maxn,a[i]&a[j]);
				}
			}
		}
		printf("%d",maxn);
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		printf("%d",ans);
		return 0;
	}else if(n<=20){
		int maxn=-1e9;
		for(int i=1;i<(1<<n);i++){
			int ans=(1<<20)-1,cnt=0;
			for(int j=1;j<=20;j++){
				if(i&(1<<(j-1))){
					cnt++;
					ans=ans&a[j];
				}
				
			}
			if(cnt==m){
				maxn=std::max(maxn,ans);
			}
		}
		printf("%d",maxn);
		return 0;
	}else{
		std::sort(a+1,a+n+1);
		printf("%d",a[n-m+1]);
		return 0;
	}
}
