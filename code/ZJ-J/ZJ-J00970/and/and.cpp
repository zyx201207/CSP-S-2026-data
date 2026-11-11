#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int n,m,a[maxn],ma,ans,cnt[35];
bool vis[maxn];
struct LXC{
	int x,id;
	bool operator<(const LXC b)const{return x<b.x;}
}hurt[maxn];
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
void dfs(int fir,int bu){
	if(bu==m+1){
		int sum=a[cnt[1]];
		for(int i=2;i<=m;i++){
			sum&=(a[cnt[i]]);
		}
//		for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
//		printf("\n");
//		printf("%d\n",sum);
		ans=max(ans,sum);
		return;
	}
	for(int i=fir+1;i<=n;i++){
		cnt[bu]=i;
		dfs(i,bu+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),ma=max(ma,a[i]);
	if(n<=20){
		dfs(0,1);
		printf("%d",ans);
		return 0;
	}
	if(n>10000){
		for(int i=1;i<=n;i++){
			hurt[i]=(LXC){ma-(ma&a[i]),i};
		}
		sort(hurt+1,hurt+1+n);
		ans=ma;
		for(int i=1;i<=m;i++){
			ans&=a[hurt[i].id];
		}
		printf("%d",ans);
		return 0;
	}
	else{
		if(n==m){
			int sum=a[1];
			for(int i=1;i<=n;i++) sum&=a[i];
			printf("%d",sum);
			return 0;
		}
		for(int k=1;k<=n;k++){
			int X=a[k];
			for(int i=1;i<=m;i++){
				int mi=INT_MAX,p;
				for(int j=1;j<=n;j++){
					int h=X-(X&a[j]);
					if(h<mi && !vis[j]){
						mi=h;
						p=j;
					}
				}
//				printf("%d\n",p);
				vis[p]=1;
				X&=a[p];
			}
			ans=max(ans,X);
		}
		printf("%d",ans);
	}
	return 0;
}
