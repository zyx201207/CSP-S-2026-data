#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],d[500010],ans;
int read(){
	int x=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*flag;
}
void write(int x){
	if(!x) return ;
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,sum=a[i]*i-d[i]-m;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(mid-1)-d[mid-1]>=sum) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	if(ans==0) putchar('0');
	else write(ans);
	return 0;
}
