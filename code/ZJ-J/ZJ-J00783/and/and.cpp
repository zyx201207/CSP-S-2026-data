#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
long long ans = 0;
bool flag = 1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		int j = 31;
		while(!((1ll*(1<<(j-1)))&a[i])){
			j--;
		}
		for(j;j>=1;j--){
			if(!(a[i]&(1<<(j-1)))){
				flag = 0;
			}
		}
	}
	if(n<=25){
		for(int mask = 0;mask<=(1<<n)-1;mask++){
			int num = 0;
			long long sum = (1<<n)-1;
			for(int j = 1;j<=n;j++){
				if((1<<(j-1))&mask){
					num++;
					sum&=a[j];
				}
			}
			if(num == m){
				ans = max(ans,sum);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	else if(n==1){
		for(int i = 1;i<=n;i++){
			ans = max(ans,a[i]);
		}
		printf("%lld",ans);
		return 0;
	}
	else if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i!=j){
					ans = max(ans,a[i]&a[j]);
				}
			}
		} 
		printf("%lld",ans);
		return 0;
	}
	else if(n==m){
		ans = (1<<n)-1;
		for(int i = 1;i<=n;i++){
			ans&=a[i];
		}
		printf("%lld",ans);
		return 0;
	}
	else if(flag){
		sort(a+1,a+1+n);
		printf("%lld",a[n-m+1]);
		return 0;
	}
	return 0;
}
