#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%lld %lld",&x,&y);
		}
		printf("%lld\n",k/2);
	}
	return 0;
}
