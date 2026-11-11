#include <cstdio>
#include <algorithm>

const int maxn=500005,maxm=300005;

int a[maxn];
int n,m;

namespace force{
	bool ok(){return n<=5000;}
	
	int ans[maxm];
	int sta[maxn],top=0;
	int c[maxn];
	void solve(){
		for(int i=1;i<=n;i++){
			top=0;
			for(int j=1;j<=m;j++) c[j]=0;
			for(int j=i;j<=n;j++){
				if(!c[a[j]]) sta[++top]=a[j],c[a[j]]++;
				else while(top&&sta[top]!=a[j]) c[sta[top]]--,top--;
			}
			for(int j=1;j<=m;j++) if(c[j]) ans[j]++;
		}
		for(int i=1;i<=m;i++) printf("%d%c",ans[i]," \n"[i==m]);
	}
}

namespace better{
	bool vis[maxm];
	int ans[maxm];
	int next[maxn];
	void solve(){
		for(int i=n;i>=1;i--){
			for(int j=i+1;j<=n;j++)
				if(a[j]==a[i]){
					if(next[j]==0) next[i]=j;
					else next[i]=next[j];
					break;
				}
		}
//		for(int i=1;i<=n;i++)printf("%d%c",next[i]," \n"[i==n]);
		for(int i=1;i<=n;i++){
			int last=i;
			for(int j=i;j<=n;last=j){
				if(next[j]) j=next[j];
				if(j==last){
					for(int k=j;k<=n;k++) vis[a[k]]=true;
					break;
				}
			}
			for(int j=1;j<=m;j++) if(vis[j]) ans[j]++,vis[j]=false;
		}
		for(int i=1;i<=m;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	if(force::ok()) force::solve();
	else better::solve();
	return 0;
}
