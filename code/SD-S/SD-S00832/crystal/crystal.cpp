#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n;
long long suf[N];
long long m;
bool check(int k){
	long long sumk=suf[n]-suf[n-k];
	long long need=1LL*a[n-1]*k-sumk;
	return need<=m;
}
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	suf[n]=0;
	for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2; 
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			mid-1; 
		}	
	}
	cout<<ans;
	return 0;
}

