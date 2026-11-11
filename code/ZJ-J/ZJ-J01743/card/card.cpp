#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[300010],ans[300010];
bool vis[500010];
inline int read(){
	int num=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++){			
			if(vis[a[j]]){
				for(int k=cnt[a[j]]+1;k<j;k++) vis[a[k]]=0;
				cnt[a[j]]=j;
			}
			else{
				cnt[a[j]]=j;
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++) if(vis[j]) ans[j]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
}
