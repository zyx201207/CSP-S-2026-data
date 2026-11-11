#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;

long long a[maxn],d[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=0;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	long long i=1,j=1;
	long long s=0,maxlen=0,tmplen=1;
	while(i<=j && i<n && j<n){
		s+=(j-i+1)*d[j];
		j++;
		while(s>m){
			s-=(a[j+1]-a[i+1]);
			i++;
		}
		maxlen=max(maxlen,j-i+1);
	}
	printf("%lld",maxlen);
	return 0;
}
