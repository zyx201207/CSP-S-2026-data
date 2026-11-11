#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
int n,m,a[200005],ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void dfs(int x,int sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(x==n) return;
	dfs(x+1,sum&a[x+1],cnt+1);
	dfs(x+1,sum,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		printf("%lld",ans);
	}else if(n<=2000){
		for(int i=1;i<=n-m;i++) dfs(i,a[i],1);
		printf("%lld",ans);
	}else{
		sort(a+1,a+n+1);
		printf("%lld",a[n-m-1]);
	}
	return 0;
}