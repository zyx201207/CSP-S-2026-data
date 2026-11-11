#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+5;
int n,c,T,f[15][15];
ll d,x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	for(;T--;){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		ll C=x[2]-x[1];
		int g=d/C;
		int ans=0;
		for(int i=1;i+g+1<=n;i++)
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}