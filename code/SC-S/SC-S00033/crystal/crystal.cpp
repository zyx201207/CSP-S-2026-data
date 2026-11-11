#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool flag=true;
	bool flag2=true;
	for(long long int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)flag=false;
	}
	long long int cha=a[2]-a[1];
	for(long long int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cha)flag2=false;
	}
	if(flag==true){
		long long int sum=0;
		for(long long int i=1;i<=n;i++){
			sum+=i;
			if(sum>m){
				printf("%lld",i);
				return 0;
			}
		}
	}
	if(flag2==true){
		long long int sum=0;
		for(long long int i=1;i<=n;i++){
			sum+=i*cha;
			if(sum>m){
				printf("%lld",i);
				return 0;
			}
		}		
	}
	sort(a+1,a+n+1);
	long long int maxn=-1;
	for(long long int i=1;i<=n;i++){
		long long int sum=0;
		long long int duan=0;
		for(long long int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				duan=j;
				break;
			}
		}
		maxn=max(maxn,i-duan);
	}
	printf("%lld",maxn);
	return 0;
}