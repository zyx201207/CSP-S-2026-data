#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
int n,m,a[maxn],ans,f[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
//bool cmp(int x,int y){return x>y;}
void DFS(int step,int x,int chs){
	if(chs==m){ans=max(ans,x);return;}
	if(step>n) return;
	if(x==0) DFS(step+1,a[step],chs+1);
	else DFS(step+1,x&a[step],chs+1);
	DFS(step+1,x,chs);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
//	sort(a+1,a+1+n,cmp);
	if(n==m){
		for(int i=1;i<=n;i++) ans&=a[i];
		printf("%d",ans);
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		printf("%d",ans);
		return 0;
	}
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j) ans=max(ans,a[i]&a[j]);
		printf("%d",ans);
		return 0;
	}
	if(n<=20){
		DFS(1,0,0);
		printf("%d",ans);
		return 0;
	}
	DFS(1,0,0);
	printf("%d",ans);
	return 0;
}
// I love CCF very much!!!