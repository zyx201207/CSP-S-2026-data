#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m;
long long a[N];
long long t[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		t[i]=(a[i]-a[i-1])*(i-1)*1ll+t[i-1];
	}
	for(int i=1;i<=n;i++){
		if(t[i]<=m) ans=i;
	}
	printf("%d",ans);
	return 0;
} 
