#include<bits/stdc++.h>
using namespace std;

struct node{
	int ds,num;
};
int c,t;
int n,d,x[2000005];
node ans[2000005];
void csp_gwzx(int i,int sum){
	if(i>n)return ;
	if(ans[i].ds>sum){
		ans[i].ds = sum;
		ans[i].num = 1;
	}
	else if(ans[i].ds==sum){
		ans[i].num++;
	}
	else{
		return ;
	}
	if(i==n)return ;
	int j = i+1;
	while(d>=x[j]-x[i]){
		csp_gwzx(j,sum+1); 
		j++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i = 1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i = 1;i<=n;i++){
			ans[i].ds = 1e9,ans[i].num =0;
		}
		csp_gwzx(x[1],0);
		long long sum  = 0;
		for(int i = 1;i<=n;i++){
			if(ans[i].num==2){
				sum++;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
