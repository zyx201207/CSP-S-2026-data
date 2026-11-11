#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[1000007],val[1000007];
int cnt=0,head[1000007],to[1000007],nxt[1000007];
void add(int u,int v){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int tnt[1000007],maxn=0;
void dfs(int a,int b,int dep){
	if(a>b) return;
	dep++;
	for(int i=head[a];i;i=nxt[i]){
		int v=to[i];
		
		if(v==b){
			tnt[dep]++;
			maxn=max(maxn,dep+1);
			return;
		}
		dfs(v,b,dep);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(c==11||c==12){
			int cha=a[2]-a[1];
			if((cha/d)==1) printf("0\n");
			int fei=cha/d;
			printf("%d\n",max((n-fei),0));
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
				add(i,j);
			}
		}
		int ans;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
//				memset(tnt,0,sizeof tnt);
				maxn=0;
				dfs(i,j,0);
				for(int i=1;i<=maxn;i++){
					if(tnt[i]){
						if(tnt[i]==2)
							ans++;
						tnt[i]=0;
						break;
					}
					tnt[i]=0;
				}
				for(int i=1;i<=maxn;i++) tnt[i]=0;			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		for(int i=1;i<=cnt;i++){
			head[i]=nxt[i]=to[i]=0;
		}
		cnt=0,ans=0;
	}
	return 0;
}