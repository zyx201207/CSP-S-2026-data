//孟楚程  西安辅轮中学  SN-S00327 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int buflen=1<<22,maxn=5e5+5;
int pos,len,n,m,ans,a[maxn],sum[maxn];char buf[buflen];
char gc(){
	if(pos==len) len=fread(buf,1,buflen,stdin),pos=0;
	return pos==len?EOF:buf[pos++];
}
int rad(){
	int x=0,f=1;char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;if(ch==EOF) return 0;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=gc();}return x*f;
}
bool check(int qi,int zh){
	int yi=a[zh]*(zh-qi+1);int x=sum[zh]-sum[qi-1];
	if(yi-x<=m) return true;return false;
}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	n=rad();m=rad();ans=1;
	for(int i=1;i<=n;i++) a[i]=rad();
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){//枚举起点 
		int len=0;
		for(int j=1<<22;j;j>>=1)if(i+len+j-1<=n){
			if(check(i,i+len+j-1)) len+=j;
		}ans=max(ans,len);
	}cout<<ans<<'\n';
	return 0;
}
