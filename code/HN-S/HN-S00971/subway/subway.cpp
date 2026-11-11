#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1005;
const int M=842150450;
int read(){
	int w=1,x=0; char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-') w=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	return x*w;
}
int c,n,m,d,q,dis[N][N];
ll f[N][N];
int w[N],k[505],e[N][N];
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	memset(e,50,sizeof(e));
	cout<<e[1][1]<<' ';
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		int a,b,c,d;
		if(k[i]==1) a=read(),b=read();
		else{
			a=read(); b=read(); c=read(); d=read();
		    e[a][c]=min(e[a][c],b+d); e[c][a]=min(e[c][a],b+d);
		}
	}
	memset(f,50,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=i;k<=j;k++){
				f[i][j]=min(f[i][j],(ll)(e[i][k]+e[k][j])); 
			} 
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		l=read(); r=read();
		cout<<f[l][r]<<'\n';
	}
	return 0;
}
