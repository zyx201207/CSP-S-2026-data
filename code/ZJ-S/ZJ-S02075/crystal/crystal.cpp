#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,k,maxx=0;
	long long m,t=0,p=1;
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t+=a[i];
		k+=1;
		if(k*a[i]-t>m){
			k-=1;
			t-=a[p];
			p+=1;
		}
		if(k>maxx)maxx=k;
	}
	printf("%lld",maxx);
}
