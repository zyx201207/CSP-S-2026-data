#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long int n,m,a[maxn],ans=-1;
bool x=0,y=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			x=1;
			break;
		}
	}
	if(x==0){
		long long int k=1;
		while(m>0){
			if(k*(k+1)/2>m){
				if(k>n)k=n;
				printf("%lld",k);
				return 0;
			}
			k++;
		}

	}
	int cha=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=cha)y=1;
	}
	if(y==0){
		long long int k=1;
		while(m>0){
			if(k*(a[n]+a[n]-(k-1)*cha)/2>m){
				if(k>n)k=n;
				printf("%lld",k);
				return 0;
			} 
		}
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		int t=m;
		for(int j=i-1;j>=1;j--){
			t-=a[i]-a[j];
			if(t>=0){
				if(ans<i-j+1)ans=i-j+1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
