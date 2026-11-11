#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],d[5000005],k=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		d[i]=a[i]-a[i-1];
	}

		for(int i=2;i<=n;++i){
			long long x=d[i]*(i-1);
			if(m>=x){
				m-=x;
				k++;
			}else break;
		}
	printf("%lld",k);
	return 0;
} 
