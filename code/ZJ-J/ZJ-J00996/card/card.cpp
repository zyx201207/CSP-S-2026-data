#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005],f[500005];
bool flg=1;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<a[i-1]) flg=0;
	}
	if(n>=5000&&m==2){
		int cnt1=0,cnt2=0;
		if(a[n]==1){
			for(int i=1;i<=n;i++) if(a[i]==1) cnt1++;
			printf("%d %d",n,n-cnt1-1);
		}else{
			for(int i=1;i<=n;i++) if(a[i]==2) cnt2++;
			printf("%d %d",n-cnt2-1,n);
		}
	}
	if(flg==0){
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof f);
			for(int j=i;j<=n;j++){
				if(f[a[j]]==0) f[a[j]]=j;
				else{
					for(int k=f[a[j]];k<j;k++) f[a[k]]=0;
					f[a[j]]=j;
				}
			}
			for(int j=1;j<=m;j++) if(f[j]) cnt[j]++;
		}
		for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	}else{
		for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) printf("%d ",i-1);
		printf("%d",n);
	}
	return 0;
}