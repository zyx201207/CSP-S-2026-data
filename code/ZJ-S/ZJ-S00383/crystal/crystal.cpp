#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m;
int a[N];
int sum[N];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);int l=1;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while((i-l+1)*a[i]-sum[i]+sum[l-1]>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
