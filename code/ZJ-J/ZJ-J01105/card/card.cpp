#include<bits/stdc++.h>
using namespace std;
const int maxm=300005;
const int maxn=500005;
int n,m,c[maxn],b[maxm],a[maxn],d[maxn],topp=1;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){int ret=0,f=1;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
//		for(int j=1;j<=topp;j++)printf("%d ",d[j]);
//		printf("\n");
		for(int j=1;j<=topp;j++)d[j]=0,b[j]=0;
		topp=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				d[topp]=a[j];
				//c[a[j]]=i;
				topp++;
				b[a[j]]=topp-1;
			}else{
				//printf("%d\n",b[a[j]]);
				for(int k=b[a[j]]+1;k<=topp-1;k++)b[d[k]]=0;
				topp=b[a[j]]+1;
			}
		}
		for(int j=1;j<=topp;j++)c[d[j]]++;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",c[i]);
	}
	return 0;
}
