#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long res=0;
	short f=1;
	while(c<'0' || c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
void write(long long x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int aaaaa,n,m,d,q;
long long a[500005],tim[500005][25];
int t1[505],t2[500005];
int num[500005][25];
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	aaaaa=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		t1[i]=read();
		for(int j=1;j<=t1[i];j++){
			int v=read();
			num[v][++t2[v]]=i;
			tim[v][t2[v]]=read();
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e12;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t2[i];j++){
			for(int k=1;k<=t2[i];k++){
				if(num[i][j]==num[i][k])
					f[num[i][j]][num[i][k]]=0;
				else{
					f[num[i][j]][num[i][k]]=min(
					f[num[i][j]][num[i][k]],
					tim[i][j]+tim[i][k]
					);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}*/
	while(q--){
		int x=read(),y=read();
		long long ans=1e12;
		for(int i=1;i<=t2[x];i++){
			for(int j=1;j<=t2[y];j++){
				ans=min(ans,f[num[x][i]][num[y][j]]+tim[x][i]+tim[y][j]);
			}
		}
		write(ans+a[x]+a[y]);
		putchar('\n');
	}
	return 0;
}
