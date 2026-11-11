#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],mx;
unsigned long long sum;
bool A=1,B=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			A=0;
		}
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			B=0;
		}
	}
	sort(a+1,a+1+n);
	if(A||B){
		long long sss=0;
		for(int i=n;i>=1;i--){
			sss+=a[n]-a[i];
			if(sum>m){
				cout<<n-i;
				return 0;
			}
		}
	}
	for(long long x=n;x>=1;x--){
		sum=0;
		bool p=1;
		long long ss;
		if(x<=mx){
			break;
		}
		for(int i=x;i>=1;i--){
			sum+=a[x]-a[i];
			if(sum>m){
				p=0;
				ss=x-i;
				mx=max(mx,ss);
				break;
			}
		}
		if(p){
			mx=max(mx,x);
		}
	}
	printf("%lld",mx);
	return 0;
}