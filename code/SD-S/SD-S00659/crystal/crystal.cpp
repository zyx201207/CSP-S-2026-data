#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i+1);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	while(r<=n){
		if(a[r]*(r-l)-sum[r-1]+sum[l-1]<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++; 
		}
	}
	cout<<ans;
	return 0;
} 
