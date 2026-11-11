//孟楚程  西安辅轮中学  SN-S00327 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int buflen=1<<22,maxn=2e6+5;
int pos,len,n,d,a[maxn],xie;char buf[buflen];
char gc(){
	if(pos==len) len=fread(buf,1,buflen,stdin),pos=0;
	return pos==len?EOF:buf[pos++];
}
int rad(){
	int x=0,f=1;char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;if(ch==EOF) return 0;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=gc();}return x*f;
}
void dfs(int yuan,int nw,int ned){
	if(nw==ned){xie++;return;}
	for(int i=nw+1;i<=ned;i++){if(a[i]-a[nw]>d) break;dfs(yuan,i,ned);}
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int c=rad(),t=rad();
	while(t--){
		n=rad(),d=rad();int ans=0;
		for(int i=1;i<=n;i++) a[i]=rad();
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){xie=0;dfs(i,i,j);if(xie==2) ans++;}
		cout<<ans<<'\n';
	}
	return 0;
}
