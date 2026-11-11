#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long ret=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret*f;
}
const int maxn=500005;
int n,ans;
long long m,a[maxn],s[maxn];
bool check(int x){
	for(int i=x;i<=n;i++){
		long long cnt=0;cnt=((long long )(a[i]*(x-1))-((long long)(s[i-1]-s[i-x])));
		if(cnt<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int L=1,R=n;
	while(L<=R){
		int mid=(L+R)/2;
		if(check(mid)) L=mid+1,ans=mid;
		else R=mid-1;
	}
	printf("%d",ans);
	return 0;
}