#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
long long m,a[500001];
int n,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(m>0){
		if(m>=min(abs(a[n/2+1-i]-a[n/2+1]),abs(a[n/2+1]-a[n/2+1+i]))){
			sum++;
			m=m-min(abs(a[n/2+1-i]-a[n/2+1]),abs(a[n/2+1]-a[n/2+1+i]));
		}
		}else{
			break;
		}
	}
	printf("%d",sum+1);
	return 0;
}
