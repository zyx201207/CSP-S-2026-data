#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int T,c,n,d,a[2000005],f[5005][5005],p[5005],ans;
int dfs(int now,int to,int cnt,int mx){
	if(~f[now][to]) return f[now][to];
	if(cnt>mx) return 0;
	if(cnt==mx&&now<to) return 0;
	if(now>=to) return cnt==mx;
	for(int i=now+1;i<=to&&a[i]-a[now]<=d;i++) f[now][to]+=dfs(i,to,cnt+1,mx);
	++f[now][to];
	if(f[now][to]==2) ans++;
	return f[now][to];
}
void slove(int now,int to){
	int sum=0;
	for(int i=now,j=now+1;i<to;){
		if(a[j]-a[i]>d) return;
		while(j<=to&&a[j]-a[i]<=d) j++;
		i=j-1;sum++;
	}
	dfs(now,to,0,sum);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		memset(f,-1,sizeof f);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)slove(i,j);
		printf("%d\n",ans);
	}
	return 0;
}
