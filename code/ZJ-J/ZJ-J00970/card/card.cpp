#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
int n,m,a[maxn],s[maxn],top,lst[maxn],cnt[maxn];
bool vis[maxn];
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int t=1;t<=n;t++){
		top=0;
		memset(s,0,sizeof s);
		memset(vis,0,sizeof vis);
		for(int i=t;i<=n;i++){
			int j=1;
			while(s[j]!=a[i] && j<=n) j++;
			if(j==n+1){
				s[++top]=a[i];
			}
			else{
				top=j;
			}
		}
		for(int i=1;i<=top;i++){
//			printf("%d ",s[i]);
			if(!vis[s[i]]) cnt[s[i]]++,vis[s[i]]=1;
		}
//		printf("\n");
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}
