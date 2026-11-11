#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n, ans=-1;
long long m, sum;
long long  a[maxn],c[maxn];
int dp[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	c[1]=a[1];
	for(int i=2;i<=n;++i){
		c[i]=a[i]+c[i-1];
	}
	for(int i=2;i<=n;++i){
		if((c[i-1]+m)/(i-1)>=a[i]){
			sum=i;	
		}else{
			for(int j=1;j<=i;++j){
				if( (c[i-1]-c[j]+m)/(i-j-1)>=a[i] ){
					sum=i-j;
					break;
				}
			}
		}
		ans=max(ans,sum);
	}

	cout<<ans;
	return 0;
} 