#include<bits/stdc++.h>
using namespace std;

int c,t,n;
long long d,x[2000010];

int dfs(int a,int b){
	if(a==b){
		return 1;
	}
	int v=0;
	for(int i=a+1;i<=b;i++){
		if(x[i]-x[a]<=d){
			v+=dfs(i,b);
		}
	}
	return v;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(;t--;){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
            	if(dfs(i,j)==2){
            		ans++;
            	}
            }
		}
		printf("%d\n",ans);
	}
}
