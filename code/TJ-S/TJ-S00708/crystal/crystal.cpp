#include<cstdio>
#include<algorithm>
long long n,m,a[500005],ans=0,c=0;
void dfs(int now){
	int s=0;
	for(int i=1;i<=now;i++){
		s+=a[now]-a[i];
	}
	if(s<=m&&now>ans){
		c=s;
		ans=now;
	}
}
int main(){
	freopen("crystal.in","r","stdin");
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int i=1;i<=n;i++)dfs(i);
	printf("%lld\n",ans);
	freopen("crystal.out","w","stdout");
	return 0;
} 
