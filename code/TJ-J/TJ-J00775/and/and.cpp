#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=1;
long long a[200100];
void f(long long q){
	if(q==0){
		return;
	}
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<' '<<ma<<endl;
		ma=max(ma,a[q]&a[i]);
	}
	q-=1;
	f(q);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	if(m==n){
		long long c=a[1];
		for(int i=1;i<=n;i++){
			c=c&a[i];
		}
		printf("%lld",c);
		return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		printf("%lld",ma);
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		printf("%lld",ma);
		return 0;
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ma=max(ma,a[i]&a[j]&a[k]);
					//cout<<ma<<endl;
				}
			}
		}
		printf("%lld",ma);
		return 0;
	}
	f(m);
	printf("%lld",ma);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
