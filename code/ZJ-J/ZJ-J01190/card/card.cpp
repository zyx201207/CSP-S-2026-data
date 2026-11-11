#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-48,ch=getchar();
	return ret*f;
}
const int maxn=5e5+5,maxm=3e5+5;
int n,m;
int a[maxn],cnt[maxn];
int nxt[maxn],nw[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)nw[i]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=nw[a[i]];
		nw[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			while(nxt[j]<=n)j=nxt[j];
		}
	}
	for(int i=1;i<=m;i++){
		if(i==m)printf("%d\n",cnt[i]);
		else printf("%d ",cnt[i]);
	}            
	return 0;
}