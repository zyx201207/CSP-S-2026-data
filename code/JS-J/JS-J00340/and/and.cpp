#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,p=0;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n,cmp);
	p=a[1];
	for(int i=1;i<m;i++){
		p&=a[i];
	}printf("%lld",p);
	return 0;
}
