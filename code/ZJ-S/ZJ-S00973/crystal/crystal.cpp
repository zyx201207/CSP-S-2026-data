#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int n,m,L,R,ans=1,a[500005],s[500005];
bool check(int mid){
	int mn=INT_MAX;
	for(int i=mid;i<=n;i++) mn=min(mn,a[i]*(mid-1)-(s[i-1]-s[i-mid]));
//	cerr<<"check("<<mid<<"):"<<mn<<endl;
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	L=1,R=n;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%lld",ans);
	return 0;
}