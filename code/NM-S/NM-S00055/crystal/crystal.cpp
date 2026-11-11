#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[500010],b[500010],ans=1,ma=0,last,need;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	}
	for(int i=1;i<=n;i++){
		ans=0;
		last=m;
		for(int j=i;j>=1;j--){
			need=b[j]-b[i];
			if(last-need>=0){
				ans++;
				last-=need;
			}
		}
		if(ans>ma){
			ma=ans;
		}
	}
	printf("%lld",ma);
	return 0;
}
