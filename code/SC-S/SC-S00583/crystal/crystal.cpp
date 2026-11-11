#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long mx=0;
	long long flag=0;
	scanf("%lld%lld",&n,&m);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==i){
			flag++;
		}
		if(mx<=a[i]){
			mx=a[i];
		}
		sum+=a[i];
	}
	if(m==0){
		printf("0");
		return 0;
	} 
	long long sun=0;
	if(flag==n){
		long long i=0;
		while(sun<=m){
			i++;
			sun+=i;
		}
		printf("%lld",i);
		return 0;
	}
	bool flags=true;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flags=false;
			break;
		}
	}
	if(flags==true){
		long long com=a[2]-a[1];
		long long san=0;
		while(san<=m){
			san++;
			sun+=san*com;
		}
		printf("%lld",san);
		return 0;
	}
	if(mx*n-sum<=m){
		printf("%lld",mx*n-sum);
		return 0;
	}
	sort(a+1,a+n+1);
	long long mxx=0;
	for(int i=1;i<=n;i++){
		int j=i;
		long long su=0;
		while(j>=1){
			j--;
			su+=a[i]-a[j];
			if(su>m){
				if(i-j!=1&&i-j>mxx){
					mxx=i-j;
				}
				break;
			}
			else if(su==m){
				if(i-j+1>mxx){
					mxx=i-j+1;
				}
				break;
			}
		}
	}
	printf("%lld",mxx);
	return 0;
}