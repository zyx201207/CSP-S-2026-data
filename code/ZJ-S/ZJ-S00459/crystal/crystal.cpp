#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[511451],ans,s[511451];
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
inline int ck(int x){
	int l=1,r=x,mid,ans=1;
	for(;l<=r;){
		mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m)ans=x-mid+1,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++)ans=max(ans,ck(i));
	cout<<ans;
	return 0;
}
/*
14:40~14:50 think+code
*/