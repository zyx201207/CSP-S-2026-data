#include<bits/stdc++.h>
using namespace std;
const int MAXN=508;
const int MAXM=5e5+8;
int c,n,m,d,q,w[MAXN],t[MAXN][MAXM];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		for(int j=1;j<=k;j++){
			int x,y;
			x=read(),y=read();
			t[i][j]=y;
		}
	}
	while(q--){
		int l,r;
		l=read(),r=read();
		int sum=w[l]+w[r];
		for(int i=l+1;i<=r;i++)sum+=t[i-1][i-1]+t[i-1][i];
		cout<<sum<<"\n";
	}
	return 0;
} 
