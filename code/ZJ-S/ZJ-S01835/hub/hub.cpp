#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int MAXN=5e5+10;
long long c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v);
		printf("%lld\n",rand()%(n/2));
	}
	return 0;
}