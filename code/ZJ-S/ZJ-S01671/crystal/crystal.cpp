#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn];
int sum[maxn];
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
int ans;
bool check(int x,int p){
	return (a[p]*(x+1)-(sum[p]-sum[p-x-1]))<=m;
}
void solve(int p){
	int l=0,r=p-1,cur=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,p))l=mid+1,cur=mid;
		else r=mid-1;
	}
	ans=max(ans,cur+1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		solve(i);
	}
	printf("%lld\n",ans);
	return 0;
} 
