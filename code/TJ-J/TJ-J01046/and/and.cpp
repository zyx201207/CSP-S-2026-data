#include <cstdio>
#include <algorithm>
const int MAXN=2*100009;
int a[MAXN];
int n,m;
bool cmp(int i,int j){
	return i<j;
}
int dfs(int now,int summ,int answer){
	if(summ==0) return answer;
	if(now>n) return -0x3f3f3f3f;
	int ans=answer;
	if(summ) ans=std::max(ans,answer&a[now]&dfs(now+1,summ-1,answer&a[now]));
	ans=std::max(ans,answer&dfs(now+1,summ,ans));
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+n+1,cmp);
	int ans;
	for(int i=1;i<=m;i++){
		if(i==1) ans=a[i];
		ans^=a[i];
	}
	//int answer=0;
	//for(int i=1;i<=n;i++) answer=std::max(answer,dfs(1,m-1,a[i]));
	//printf("%d\n",answer);
	//printf("%d\n",12&15);
	printf("%d\n",ans);
	return 0;
} 
