// SN-J01021 Ê¦´ó01¿¼³¡  ³Â¼ÎÏé
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x[200005];
long long a;
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	sort(x+1,x+n+1);
	long long k=unique(x+1,x+n+1)-x-1;
	long long mid=k/2;
	printf("%lld",x[mid]);
	return 0; 
}

