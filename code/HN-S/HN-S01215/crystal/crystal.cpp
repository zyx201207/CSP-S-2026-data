#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N];
int f(long long x){
	for(long long i=x;i<=n;i++){
		if(s[i]-s[i-x]+m>a[i]*x){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	long long l=0,r=n;
	while(l<r){
		long long mid=(l+r)/2;
		if(f(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l;
	return 0;
} 
