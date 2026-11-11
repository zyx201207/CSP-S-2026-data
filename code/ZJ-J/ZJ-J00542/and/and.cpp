#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long a[200010];
bool f[200010];

void dfs(int x,long long h){
	if(x>m){
		ans=max(h,ans);
		return ;
	}
	for(int i=1; i<=n; i++){
		if(f[i]==0){
			f[i]=1;
			dfs(x+1,h&a[i]);
			f[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	if(n<=20){
		ans=0;
		dfs(1,(1<<31)-1);
		printf("%lld",ans);
	}
	else if(n==1){
		printf("%lld\n",a[1]);
	}
	else if(m==n){
		ans=a[1];
		for(int i=2; i<=n; i++){
			ans&=a[i];
		}	
		printf("%lld\n",ans);
	}
	else if(m==1){
		ans=0;
		for(int i=1; i<=n; i++){
			ans=max(a[i],ans);
		}
		printf("%lld\n",ans);
	}
	else if(m==2){
		ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		printf("%lld\n",ans);
	}
	else if(m==n-1){
		ans=0;
		long long op=a[1];
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i!=j) op&=a[j];
			}
			ans=max(ans,op);
		}
		printf("%lld\n",ans);
	}
	else{
		printf("1\n");
	}
	
	return 0;
}
