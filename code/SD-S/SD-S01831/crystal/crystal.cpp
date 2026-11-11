#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int n,m,ans,a[N],s[N];
inline bool check(int x){
	bool flg=0;
	for(int i=x;i<=n;i++){
		if(a[i]*x-s[i]+s[i-x]<=m)flg=1;
	}
	return flg;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
//	if(check(315275))printf("!\n");
	printf("%lld",ans);
	return 0;
}
/*
作为退役一年后的第一战
打的应该还算可以
希望成绩能如我所愿吧 
*/
