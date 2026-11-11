#include<iostream>
using namespace std;
inline int read(){
	int f=1,s=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return f*s;
}
int c,n,m,d,q,a[150005],l,w[501][150005],k,x,y,ans=100001;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			w[i][j]=1e9;
			w[j][i]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		l=read();
		if(l==2){
			k=read();
			int p=read();
			int q=read();
			int u=read();
			w[k][q]=min(w[k][q],u);
			w[q][k]=min(w[k][q],p);
		}
	}
	for(int i=1;i<=q;i++){
		x=read(),y=read();
		for(int j=1;j<=m;j++){
			if(w[x][j]!=0&&w[j][y]!=0){
				ans=min(w[x][j]+w[j][y],ans);
			}
		}
	}
	printf("%d\n",ans);
}
