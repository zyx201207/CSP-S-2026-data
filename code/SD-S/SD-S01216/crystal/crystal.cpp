#include<bits/stdc++.h>
using namespace std;
const int N=5e5+66;
int n;
long long m,a[N];
long long hz[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
	hz[i]=hz[i+1]+a[n]-a[i];
	}
	//cout<<'\n';
	long long ans=1;
	for(int i=2;i<=n;i++){
	int l=1,r=i;
	long long an=0;
	while(l<=r){// mid-i 
	int mid=(l+r)/2;
	if((hz[mid]-hz[i])-(a[n]-a[i])*(i-mid+1)<=m){
	an=i-mid+1;
	r=mid-1;
	}
	else l=mid+1; 
	}
	ans=max(ans,an);
	//cout<<an<<' '<<hz[1]-hz[i]<<'\n';
	}
	printf("%lld",ans);
	return 0;
} 
