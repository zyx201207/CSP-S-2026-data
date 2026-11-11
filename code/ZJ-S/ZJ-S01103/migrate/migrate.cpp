#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],b[2000005],cnt,lnk[5005]; 
struct edge{
	int to,nxt;
}e[12500005];
void add_e(int x,int y){e[++cnt]=(edge){y,lnk[x]};lnk[x]=cnt;}
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+1;a[j]<=a[i]+d;j++){
				add_e(i,j);
			}
		}
	}
	return 0;
}/*
//freopen("r",".in",stdout)
//frpeoen("w",stdin,",out");
magical duoce
|<|<|<5(ow->90du
hangzou de xiyang hen huang xiang ji le xiebulaiT2 TLEde yanse kenengjiushiyaoAFOleba
*/
