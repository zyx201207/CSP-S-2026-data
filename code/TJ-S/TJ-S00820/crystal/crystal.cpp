#include<cstdio>
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long a[100009];
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a[i]);
	} 
	long long ans=0;
	for(int i=1;i<n;i++){
		ans=a[i];
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
		    ans=a[i]+j;
	    }
	}
	for(int i=1;i<=n;i++){
		if(a[i]=a[i+1]){
			ans=a[i]+a[i+1];
		}else{
			printf("%d",ans);
		}
	}
	return 0;
}
