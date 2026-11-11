#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long n,m,a[N],sum[N];
long long ans=-1;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long t;
		for(int i=1;i<=n;i++){
			cin>>t;
			a[i]=1e12+t;
			sum[i]=sum[i-1]+a[i];
		}
	if(n>N){
		for(long long i=1;i<=m;i++){
			if(i*(i-1)/2>m){
				cout<<i-1;
				break;
			}
		}
	}
	else{
		for(int ii=1;ii<=n;ii++){
			for(int j=ii+1;j<=n;j++){
				long long su=sum[j]-sum[ii-1];
				long long num=j-ii+1;
				long long ma=a[ii];
				for(int k=ii+1;k<=j;k++){
					ma=max(ma,a[k]);
				}
				for(int i=1;i<=m;i++){
					if(((su+i)/num*num==su+i)&&(su+i)/num>=ma){
						ans=max(num,ans);
						break;
					}
				}
	 		}
		}
		if(ans==-1){
			cout<<1;
		}else{
			cout<<ans;
		}
	}
	return 0;
} 
