#include<bits/stdc++.h>
using namespace std;
const long long N=1000000;
long long n,m,a[N],x;
long long fo(long long i){
	long long w=a[i]&a[i-1];
	for(long long j=2;j<m;++j){
		w=w&a[i-j];
	}
	return w;
}
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	scanf("%d",&n);
	for(long long i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n+1);
	for(long long i=n;i>=1;--i){
		int b=fo(i)
		if(b>x)
		x=b;
	}
	printf("%d\n",x) 
	return 0;
} 
