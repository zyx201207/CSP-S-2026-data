#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int n,m,a[200005],ans;
void dfs(int now,int cnt,int ad){
	if(now==n+1&&cnt!=m) return;
	if(cnt>m) return;
	if(now==n+1&&cnt==m){ans=max(ans,ad);return;}
	for(int i=now+1;i<=n+1;i++) dfs(i,cnt+1,ad&a[now]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and0.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) dfs(i,0,INT_MAX);
	printf("%d",ans);
	return 0;
}
