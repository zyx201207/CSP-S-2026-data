#include<bits/stdc++.h>
#define int long long
#define N 500050
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
inline int read(){
	int seg=0,sgn=0;char ch;
	while(!isdigit(ch))sgn|=ch=='-',ch=getchar();
	while(isdigit(ch))seg=seg*10+ch-'0',ch=getchar();
	return sgn?-seg:seg;
}
int n,m,a[N],sub[N],ans;
inline bool check(int tot){
	rep(i,tot,n){
		int sum=tot*a[i]-(sub[i]-sub[i-tot]);
		if(sum<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	rep(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	rep(i,1,n)sub[i]=sub[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}

