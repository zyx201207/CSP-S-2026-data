#include<cstdio>
#include<cstring>
int n,m,a[500001],pre[300001],ans[300001];
bool vis[300001],flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		std::scanf("%d",&a[i]);
		pre[a[i]]=i;
		flag=!vis[a[i]];
		vis[a[i]]=true;
	}if(flag){
		for(int i=1;i<=m;i++) std::printf("%d ",pre[i]);
		std::printf("\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}for(int game=1;game<=n;game++){
		for(int i=game;i<=n;i=pre[a[i]]+1) ans[a[i]]++;
	}for(int i=1;i<=m;i++) std::printf("%d ",ans[i]);
	std::printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
