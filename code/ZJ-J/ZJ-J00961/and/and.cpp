#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int n,m,a[200005],cnt[35],ans;
bool vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int j=30;j>=0;j--){
		int tot=0;
		for(int i=1;i<=n;i++) if(!vis[i]&&(a[i]&(1<<j))) tot++;
		if(tot<m) continue;
		for(int i=1;i<=n;i++) if(!vis[i]&&(a[i]&(1<<j))==0) vis[i]=1;
		ans+=(1<<j);
	}
	printf("%d",ans);
	return 0;
}
