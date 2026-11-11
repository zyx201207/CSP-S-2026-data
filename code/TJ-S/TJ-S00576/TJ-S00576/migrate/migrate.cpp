#include<cstdio>
int c,T,n;
long long d,a[2000001],ans,mn_len,mn_cnt;
void dfs(int start,int end,int cnt){
	if(start==end){
		if(cnt<mn_len){
			mn_len=cnt;
			mn_cnt=1;
		}else if(cnt==mn_len) mn_cnt++;
		return;
	}for(int i=start+1;i<=end&&a[i]-a[start]<=d;i++) dfs(i,end,cnt+1);
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::scanf("%d%d",&c,&T);
	while(T--){
		ans=0;
		std::scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) std::scanf("%lld",&a[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mn_len=0x3f3f3f3f;
				mn_cnt=0;
				dfs(i,j,0);
				ans+=(mn_cnt==2);
			}
		}std::printf("%lld\n",ans);
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
