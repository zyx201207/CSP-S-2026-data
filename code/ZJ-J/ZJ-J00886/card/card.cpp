//60·Ö 
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,maxm=100005;
int n,m,sum[maxm],cnt,flg=1; 
bool vis[maxm];
struct AS{
	int x,nxt;
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=(AS){read(),-1};
		if(a[i-1].x>a[i].x) flg=0;
	} 
	if(m<=2){
		sum[a[n].x]=n;
		for(int i=n;i;i--) if(a[i].x!=a[n].x) sum[a[i].x]++;
		for(int i=1;i<=m;i++) printf("%d ",sum[i]);
		exit(0);
	}
	if(flg){
		for(int i=1;i<=n;){
			int j=i+1;
			while(a[j].x==a[i].x) j++;
			j--;
			sum[a[i].x]=sum[a[i-1].x]+j-i+1;
			i=j+1;
		}
		for(int i=1;i<=m;i++) printf("%d ",sum[i]);
		exit(0);
	}
	for(int i=1;i<=n;i++)
	 for(int j=i+1;j<=n;j++) if(a[i].x==a[j].x){a[i].nxt=j;break;} 
	for(int len=1;len<=n;len++){
		for(int i=len;i<=n;){
			vis[a[i].x]=1;
			if(a[i].nxt!=-1&&a[i].nxt<=n) i=a[i].nxt;
			else i++;
		}
		for(int i=1;i<=m;i++) if(vis[i]) sum[i]++;
		memset(vis,0,sizeof vis);
	}
	for(int i=1;i<=m;i++) printf("%d ",sum[i]);
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
