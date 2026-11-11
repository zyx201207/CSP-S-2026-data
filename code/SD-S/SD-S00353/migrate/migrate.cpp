#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const int N=2e6+5;
int n;
LL a[N],T,x,sum,anst;
ULL d;
void dfs(int u,int e,int t){
	if(u==e&&t<=anst){
		if(t<anst) sum=0;
		sum++;
		anst=t;
		return ;
	}
	for(int i=u+1;i<=e;i++){
		if(a[i]-a[u]<=d) dfs(i,e,t+1);
		else return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	scanf("%d%lld",&c,&T);
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		LL ans=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				sum=0;
				anst=0x3f3f3f3f3f3f3f3f;
				dfs(j,i,0);
				if(sum==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
