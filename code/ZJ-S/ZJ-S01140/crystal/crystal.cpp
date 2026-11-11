#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],c[500005];
bool check(int x){
	long long s=0;
	for(int i=2;i<=x+1;i++) s+=c[i]*(i-1);
	if(s<=m) return 1;
	for(int i=1;i<=n-x;i++){
		s+=c[i+x+1]*x;
		s-=(a[i+x]-a[i]);
		if(s<=m) return 1;
	} 
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	int l=1,r=n,mid;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l+1;
	return 0;
}