#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void write(LL x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
LL n,m,a[500005],sum,ans,tmp1=1,tmp2=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	while(tmp2<=n){
		while(sum>m){
			sum=sum-a[tmp2]+a[tmp1];
			tmp1++;
		}
		ans=max(ans,tmp2-tmp1+1);
		sum+=(a[tmp2+1]-a[tmp2])*(tmp2-tmp1+1);
		tmp2++;
	}
	write(ans);
	return 0;
}
