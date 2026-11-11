#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int n,m,a[maxn],l[maxn],ans[maxm],nxt[maxn],pos[maxm];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while('0'<=ch&&ch<='9')ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(!pos[a[i]])pos[a[i]]=i;
		else nxt[pos[a[i]]]=i,pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			while(nxt[j])j=nxt[j];
		}	
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}