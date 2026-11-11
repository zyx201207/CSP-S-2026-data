#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],aa[5];
bool a1,a2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==1){
			a1=1;
			for(int j=i;j<=n;j++){
				if(a[j]==2) a2=1;
				if(a[j]==1) a2=0;
			}
		}
		if(a[i]==2){
			a2=1;
			for(int j=i;j<=n;j++){
				if(a[j]==2) a1=0;
				if(a[j]==1) a1=1;
			}
		}
		aa[1]+=a1;
		aa[2]+=a2;
	}
	printf("%lld %lld",aa[1],aa[2]);
	return 0;
}
