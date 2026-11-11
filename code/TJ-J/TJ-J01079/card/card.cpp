#include<cstdio>
#include<algorithm>
namespace force{
	int n,m;
	const int MAXN=5e5+5,MAXM=3e5+5;
	int a[MAXN];
	int ans[MAXM];
	int lastid[MAXM];
	int next[MAXN];
	bool vis[MAXN];
	void solve(){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=n;i>=1;i--) {
			if(!lastid[a[i]]) lastid[a[i]]=i;
		}
		for(int t=1;t<=n;t++){
			for(int i=t;i<=n;){
				if(lastid[a[i]]!=i) i=lastid[a[i]];
				else ans[a[i]]++,i++;
			}
		}
		for(int i=1;i<=m;i++) printf("%d%c",ans[i]," \n"[i==m]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	force::solve();
	return 0;
}
