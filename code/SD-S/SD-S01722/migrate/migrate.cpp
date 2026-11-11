#include<bits/stdc++.h>
using namespace std;
int c,T;
struct node{
	map<long long,long long>ma;
}a[2000005];
long long A[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&A[i]);
		}
		long long ans=0,sum;
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				if(A[j]-A[i]<=d){
					a[i].ma[j]=1;
					continue;
				} 
				sum=0;
				a[i].ma[j]=1e18;
				for(int l=i+1;l<j;l++){
					if(a[i].ma[l]+a[l].ma[j]<a[i].ma[j]){
						a[i].ma[j]=a[i].ma[l]+a[l].ma[j];
						sum=0;
					}
					if(a[i].ma[l]+a[l].ma[j]==a[i].ma[j]){
						sum++;
					}
					if(sum>2){
						break;
					}
				}
				if(sum==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
