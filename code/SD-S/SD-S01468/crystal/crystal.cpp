#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,sum,ans;
int a[510000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m); 
	
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		sum+=a[i];
	}
	if(n<=5000){
		
		sort(a+1,a+1+n);
		int maxx=0;
		for(int i=2;i<=n;i++){
			int sum=0,ans=0,j=i;
			while(sum<=m&&j<=n){
				if(sum+(a[j]-a[j-1])*(j-i+1)>m) break;
				sum+=(a[j]-a[j-1])*(j-i+1);
				ans++;
				j++;
			}
			maxx=max(maxx,j-i+1);
		}
		printf("%lld",maxx);
	}else{
		int ddd=a[2]-a[1];int kk=ddd;
		sum=0;
		for(int i=1;i<=n;i++){
			if(sum+kk>m){
				ans=i;
				break;
			}
			sum+=kk;
			kk+=ddd;
			
		}printf("%lld",ans);
	}
	
	return 0;
}
