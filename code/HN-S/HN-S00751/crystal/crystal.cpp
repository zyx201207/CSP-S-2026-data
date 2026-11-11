#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;

long long n,m,a[maxn],ans,sum[maxn];

long long bs(int idx){
	long long l=0,r=idx+1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if((mid-1)*a[idx]-(sum[idx-1]-sum[idx-mid])<=m){
			l=mid;
		}else{
			r=mid; 
		}
	}
	return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,bs(i));
	}
	cout<<ans;
	return 0;
}

