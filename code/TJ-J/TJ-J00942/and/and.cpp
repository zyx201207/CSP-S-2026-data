#include<cstdio>
#include<algorithm>
int n,m;
int a[100012];
int mem[10012][10012];
bool hasmem[10012][10012];
const int INF=(1<<31)-1;
bool cmp(int x,int y){
	return x>y;
}
int dfs(int now,int c){
	if(c>=m)return INF;
	if(now>n)return 0;
	if(hasmem[now][c])return mem[now][c];
	int ans=0;
	ans=std::max(ans,dfs(now+1,c));
	if(c<m)ans=std::max(ans,dfs(now+1,c+1)&a[now]);
	hasmem[now][c]=true;
	mem[now][c]=ans;
	return ans;
}
int getans(){
	if(m==1){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans=std::max(ans,a[i]);
		}
		return ans;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		return ans;
	}
	else if(n<=10000&&m<=10000)return dfs(1,0);
	
	else{
		std::sort(&a[1],&a[n+1],cmp);
		return a[m];
	}
	
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%d\n",getans());
	return 0;
}
