#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int n,m;
int a[maxn],ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int j=1,sum=0;
	for(int i=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld\n",ans);
	return 0;
}