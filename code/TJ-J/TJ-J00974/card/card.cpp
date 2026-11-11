#include<cstdio>
#include<algorithm>
int a[500010];
int cnt[300010];
int p[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			p[j]=0;
		}
		for (int now=i;now<=n;now++){
			if (!p[a[now]]){
				p[a[now]]=now;
			}
			else {
				for (int j=p[now];j<now;j++)p[a[j]]=0;
				p[a[now]]=now;
			}
		}
		for (int j=1;j<=m;j++){
			if (p[j])cnt[j]++;
		}
	}
	for (int i=1;i<=m;i++)printf("%d%c",cnt[i]," \n"[i==m]);
	return 0;
}
