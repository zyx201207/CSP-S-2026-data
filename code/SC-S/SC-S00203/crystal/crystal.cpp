#include <bits/stdc++.h>
using namespace std;

const int N=5e5+500;
int n;
long long m;
long long c[N],sum[N];

bool check(int ans){
	for(int i=ans; i<=n; i++){
		if(m+sum[i]-sum[i-ans]>=ans*c[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)scanf("%lld",&c[i]);
	sort(c+1,c+1+n);
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]+c[i];
	
	int l,r,mid;
	l=1,r=n+1;
	while(l<r){
		mid=(l+r+1)/2;
		if(!check(mid)){
			r=mid-1;
		}else{
			l=mid;
		}
	}
	cout<<l;
	return 0;
} 