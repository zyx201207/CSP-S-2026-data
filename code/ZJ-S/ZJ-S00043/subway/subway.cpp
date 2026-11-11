#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int c,n,m,d,q;
int w[500010];
vector<pair<int,int> >a[500010];
int f[600][600];
int read(){
	int sum=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=(sum<<1)+(sum<<3)+c-'0';
		c=getchar();
	}
	return sum*flag;
}
void write(int x){
    putchar(char(x%10+'0'));
    x/=10;
    if(x==0)return;
    write(x);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	memset(f,0x7f,sizeof f);
	for(int i=1;i<=m;i++){
	    f[i][i]=0;
	}
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		for(int j=1;j<=k;j++){
			int v,t;
			v=read(),t=read();
			a[i].push_back(make_pair(v,t));
		}
		for(int j=0;j<k;j++){
			for(int s=0;s<k;s++){
				if(j!=s){
					f[a[i][j].fi][a[i][s].fi]=a[i][j].se+a[i][s].se;
					f[a[i][s].fi][a[i][j].fi]=a[i][j].se+a[i][s].se;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		int u,v;
		u=read(),v=read();
		write(f[u][v]+w[u]+w[v]);
		cout<<'\n';
	}
	return 0;
}
