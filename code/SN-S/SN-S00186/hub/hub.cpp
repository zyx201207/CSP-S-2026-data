#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,ans = 0,cnt = 1,f = 0,A=1,B=1; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long pf = 0;
	a[0]=0;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		if(i > 1){
			if(a[i] != a[i-1]){
				A=0;
			}
		}
		if(i == 2){
			pf = abs(a[i]-a[i-1]);
		}
		if(i > 2){
			if(abs(a[i]-a[i-1])!=pf){
				B=0;
			}
		}
	}
	if(A==1){
		printf("%lld",n);
		return 0;
	}
	if(B==1){
		if(m >= pf*n*(n-1)/2){
			printf("%lld",n);
			return 0;
		}
		sort(a+1,a+1+n);
		int i = n;
		int k=m;
		for(int j = i-1;j >= 1;j--){
			if(k-(a[i]-a[j])>=0){
				k-=a[i]-a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		ans = 0;
		ans = max(ans,cnt);
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i = n;i >= 1;i--){
		int k=m;
		if(a[i]-a[i-1]>k)continue;
		for(int j = i-1;j >= 1;j--){
			if(k-(a[i]-a[j])>=0){
				k-=a[i]-a[j];
				cnt++;
			}
			else{
				break;
			}
			if(j == 1){
				f = 1;
				break;
			}
		}
		ans = max(ans,cnt);
		cnt=1;
		if(f) break;
	}
	printf("%lld",ans);
	return 0;
}
//1485 1386 1287 1188 1089 990 891 792 693 594 495 396 297 198 99
