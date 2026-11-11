#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long er[40]; 
long long num[40];
bool a[N][40];
long long n,m,cnt=0,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	er[0]=1;
	for(long long i=1;i<=30;i++){
		er[i]=er[i-1]*2;
	}
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		long long b;
		scanf("%lld",&b);
		for(long long j=0;j<=30;j++){
			a[i][j]=b%2;
			if(b%2==0)num[j]++;
			b/=2;
		}
	}
	cnt=n-m;
	for(long long i=30;i>=0;i--){
		if(num[i]<=cnt){
			ans+=er[i];
			cnt-=num[i];
			for(long long j=1;j<=n;j++){
				if(a[j][i]==0){
					for(long long k=i;k>=0;k--){
						if(a[j][k]==0){
							a[j][k]=1;
							num[k]--;
						}
					}
				} 
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

