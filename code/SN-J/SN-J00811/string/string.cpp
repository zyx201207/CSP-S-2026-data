//¡ı∆Ù∞≤ SN-J00811 π§¥ÛA2 
#include <bits/stdc++.h>
using namespace std;
long long n,m[200001],ma=0;char a[200001];
void bb(long long x,long long y,long long d){
	if(x>y){
		return;
	}
	if(a[x]!=a[y]){
		if(a[x+1]==a[y-1]){
			ma+=abs(m[x+1]-m[y-1]+d);
			bb(x+1,y-1,m[x+1]-m[y-1]+d); 
			return;
		}else{
			ma+=min(m[x+1]+d,m[x-1]);
			bb(x+1,y-1,m[x+1]-m[x-1]+d);
			return;
	}
	}else{
		ma+=abs(d);
		bb(x+1,y-1,m[x+1]-m[y-1]+d);
		return;
	}
	}
int main(){
	freopen("string.in","r",stdin);
	scanf("%ld",&n);
	long long o=n-1;
	while(o>=0){
	o-=1;
	scanf("%ld%s",&m[o],&a[o]);}
	if(n<=1){
	printf("0");return 0;
	}
	if(a[0]==a[n-1]){
		bb(1,n-1,m[0]-m[n-1]); 
	}else{
		ma+=(min(m[0],m[n-1]));
		bb(1,n-1,m[0]-m[n-1]);
	}
	printf("%ld",ma);
	freopen("string.out","w",stdout);
}
