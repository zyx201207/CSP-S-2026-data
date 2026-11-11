#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e5+5;
int n,ans;
LL m,a[maxn];
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while('0'<=ch&&ch<='9')ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(1+a,1+a+n);
	int j=1;LL sum=0;ans=1;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m)sum-=(a[i]-a[j]),j++;
		ans=max(ans,i-j+1);
//		printf("%lld\n",sum);
	}
	printf("%d\n",ans);
//	for(int i=1;i<=n;i++)printf("%lld\n",a[i]);
	return 0;
}