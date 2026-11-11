#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	a[0]=-1e18;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n+1);
	int maxx=1;
	long long k=0;
	int j=n;
	for(int i=n;i>0;i--){
		if(j>i){
			j=i;
		}
		while(k<=m){
			j--;
			k+=a[i]-a[j];
		}
		maxx=max(i-j,maxx);
		k-=(i-j)*(a[i]-a[i-1]);
	}
	cout<<maxx;
	return 0;
}
