#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll sum[500005],m,a[500005];
ll read(){
	ll ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=i,R=n;
		while(L<=R){
			int mid=L+R>>1;
			if(1ll*a[i]*(mid-i)-(sum[mid]-sum[i])<=m) L=mid+1;
			else R=mid-1;
		}
		int x=L-1;
		if(x>n||x<i||a[i]*(x-i)-(sum[x]-sum[i])>m) continue;
		ans=max(ans,x-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
