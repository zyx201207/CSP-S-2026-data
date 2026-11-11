//Oct31==Dec25?
//why shiyue 31 hao dengyu 12yue 25hao a
//liangji duile
#include<bits/stdc++.h>
using namespace std;
char ib[1<<25],*ip1=ib,*ip2=ib;
char ob[1<<25],*op1=ob;
inline char gc(){
	return ((ip1==ip2)&&(ip2=(ip1=ib)+fread(ib,1,1<<25,stdin)),(ip1==ip2?EOF:*ip1++));
}
inline int read(){//>=0
	int x=0;char c=gc();
	while(c<'0'||c>'9')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=gc();
	return x;
}
void final_write(){
	fwrite(ob,op1-ob,1,stdout);op1=ob;
}
inline void pc(char c){
	*op1++=c;
}
int wst[105];
void write(long long x){
	//x>=0
	int wt=0;
	while(x)wst[++wt]=x%10,x/=10;
	if(!wt)wst[++wt]=0;
	for(int i=wt;i>=1;--i)pc(wst[i]+'0');
}
int te,n,m,d,q;
//1<=n<=500
//1<=m,sum ki<=5e5,1<=ki<=m
//0<=te<=25
//1<=d<=20,
//x!=y
//ans xuyao long long
int deg[500005],w[500005];
int da[500005][25],dt[500005][25];
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	te=read();n=read();m=read();d=read();q=read();
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			int a=read(),t=read();
			int d=++deg[a];da[a][d]=i,dt[a][d]=t;
		}
	}
	for(int i=1;i<=m;++i){
		int d=deg[i];
		for(int j=1;j<=d;++j)for(int k=j+1;k<=d;++k){
			int u=da[i][j],v=da[i][k];
			f[u][v]=min(f[u][v],0ll+dt[i][j]+dt[i][k]);
			f[v][u]=min(f[v][u],0ll+dt[i][j]+dt[i][k]);
		}
	}
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i){
		long long z=f[i][k];
		for(int j=1;j<=n;++j)f[i][j]=min(f[i][j],z+f[k][j]);
	}
	while(q--){
		int x=read(),y=read();
		if(x==y){
			pc('0');pc('\n');continue;
		}
		long long ans=4e18;
		int dx=deg[x],dy=deg[y];
		for(int i=1;i<=dx;++i)for(int j=1;j<=dy;++j){
			ans=min(ans,dt[x][i]+dt[y][j]+f[da[x][i]][da[y][j]]);
		}
		write(ans+w[x]+w[y]);pc('\n');
	}
	final_write();
	return 0;
}
