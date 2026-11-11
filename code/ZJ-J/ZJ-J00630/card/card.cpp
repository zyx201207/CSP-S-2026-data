#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,maxm=300005;
int n,m,a[maxn],b[maxn],ans[maxn],Ta;
bool vis[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>=a[i-1])Ta++;
	}
	if(Ta==n){
		int cnt=0;
		for(int i=1;i<=n;){
			int j=i+1;
			while(j<=n&&a[j]==a[i])j++;
			b[++cnt]=j-1;
			i=j;
		}
		for(int i=1;i<=m;i++){
			if(i==m)printf("%d\n",b[i]);
			else printf("%d ",b[i]);
		}
		return 0;
	}
	if(m<=2){
		if(m==1){printf("%d\n",n);return 0;}
		int cnt=0,cnt_=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
			else cnt_++;
		}
		if(a[n]==1){
			printf("%d %d\n",n,cnt_);
			return 0;
		}else{
			printf("%d %d\n",cnt,n);
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(vis,0,sizeof vis);
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=cnt;k;k--){
					if(b[k]==a[j])break;
					vis[b[k]]=0;
					b[k]=0;
					cnt--;
				}
			}else{
				b[++cnt]=a[j];
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=cnt;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++){
		if(i==m)printf("%d\n",ans[i]);
		else printf("%d ",ans[i]);
	}
	return 0;
}
