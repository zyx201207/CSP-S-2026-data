#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,a[maxn],maxa,c[maxn],k,ans;
bool b[maxn][31];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){int ret=0,f=1;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int zuo(int a){
	if(a==1)return 1;
	return zuo(a/2)+1;
}
void zyx(){
	for(int i=1;i<=n;i++){
		int l=a[i];
		for(int j=1;j<=zuo(a[i]);j++){
			b[i][j]=l%2;
			//printf("%d%d %d\n",i,j,b[i][j]);
			l/=2;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),maxa=max(maxa,a[i]);
	zyx();
//	for(int i=1;i<=n;i++){
//		for(int j=zuo(maxa);j>=1;j--)printf("%d ",b[i][j]);
//		printf("\n");
//	}
	for(int i=zuo(maxa);i>=1;i--){
		k=0;
		for(int j=1;j<=n;j++){
			if(b[j][i])k++,c[k]=j;
		}
		//printf("\n%d %d %d\n",i,k,m);
		if(k>=m)break;
	}
	if(k<m){printf("%d\n",0);return 0;}
	sort(c+1,c+1+k);
	ans=a[c[k]];
	//printf("%d\n",c[k]);
	for(int i=k-1;i>=k-m+1;i--){
		//printf("%d %d\n",c[i],i);
		ans&=a[c[i]];
	}
	printf("%d\n",ans);
	return 0;
}
