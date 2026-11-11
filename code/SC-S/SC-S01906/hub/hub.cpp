#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll a,b;
	scanf("%lld%lld",&a,&b);
	for(ll i=1;i<=b;i++){
		if(i%2==1){
			printf("%d\n",1);
		}
		else printf("%d\n",2);
	}
	return 0;
}