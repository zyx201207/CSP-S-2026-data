//seoi jyun je taam fong
//lau zoi ngo san pong
//pui bun dou gwo haak am
//wai ngo keoi san zik mo tung co
#include<bits/stdc++.h>
using namespace std;
char ib[1<<25],*ip1=ib,*ip2=ib;
char ob[1<<25],*op1=ob;
inline char gc(){
	return ((ip1==ip2)&&(ip2=(ip1=ib)+fread(ib,1,1<<25,stdin)),(ip1==ip2?EOF:*ip1++));
}
inline long long read(){//>=0
	long long x=0;char c=gc();
	while(c<'0'||c>'9')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=gc();
	return x;
}
inline long long read2(){
	int f=1;
	long long x=0;char c=gc();
	while(c!='-'&&(c<'0'||c>'9'))c=gc();
	if(c=='-')f=-1,c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=gc();
	return x*f;
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
const int N=2000005;
int te,T,n;long long ans,d;
//1<=n<=2e6,1<=d<=2e18;
long long a[N];//|ai|<=1e18
long long f[N][6];//1 2 11 22 21 111 (222->22)
int p[N];
void solve(int l,int r){
	int x=l;
	for(int i=l;i<=r;++i){
		while(x<r&&a[x+1]-a[i]<=d)++x;
		p[i]=x;memset(f[i],0,sizeof(f[i]));
		//for(int j=0;j<6;++j)f[i][j]=0;
	}
	for(int i=l;i<=r;++i){
		++f[i][0];
		ans+=f[i][1]+f[i][3];
		if(i==r)break;
		int x=p[i];
		//fen lei tao lun
		if(f[i][0]){
			if(x==i+1)f[x][0]+=f[i][0];
			else if(x==i+2)f[x][2]+=f[i][0];
			else f[x][5]+=f[i][0];
		}
		if(f[i][1]){
			ans+=f[i][1]*(x-i-1);
			if(x==i+1)f[x][1]+=f[i][1];
			else f[x][3]+=f[i][1];
		}
		if(f[i][2]){
			int y=p[i-1];
			if(x==y){
				ans+=f[i][2]*(x-i-1);
				if(x==i+1)f[x][1]+=f[i][2];
				else f[x][3]+=f[i][2];
			}else{
				//i+1~y +2
				//y+1~x +1
				ans+=f[i][2]*(y-i);
				if(y==i){
					if(x==i+1)f[x][0]+=f[i][2];
					else if(x==i+2)f[x][2]+=f[i][2];
					else f[x][5]+=f[i][2];
				}else{
					if(x==y+1)f[x][4]+=f[i][2];
					else f[x][5]+=f[i][2];
				}
			}
		}
		if(f[i][3]){
			int y=p[i-1];
			if(x!=y){
				ans+=f[i][3]*(x-y-1);
				if(y==i){
					if(x==i+1)f[x][1]+=f[i][3];
					else f[x][3]+=f[i][3];
				}else{
					f[x][3]+=f[i][3];
				}
			}
		}
		if(f[i][4]){
			int y=p[i-1];
			if(x!=y){
				if(y==i){
					if(x==i+1)f[x][0]+=f[i][4];
					else if(x==i+2)f[x][2]+=f[i][4];
					else f[x][5]+=f[i][4];
				}else{
					if(x==y+1)f[x][4]+=f[i][4];
					else f[x][5]+=f[i][4];
				}
			}
		}
		if(f[i][5]){
			int y=p[i-1],z=max(i,p[i-2]);
			if(x==y){
				if(x==z){
					//uh....how to write this part
					//i don't know, too complicated to think
				}else{
					ans+=f[i][5]*(x-z-1);
					if(x==i+1)f[x][1]+=f[i][5];
					else f[x][3]+=f[i][5];
				}
			}else{
				ans+=f[i][5]*(y-z);
				if(y==i){
					if(x==i+1)f[x][0]+=f[i][5];
					else if(x==i+2)f[x][2]+=f[i][5];
					else f[x][5]+=f[i][5];
				}else{
					if(x==y+1)f[x][4]+=f[i][5];
					else f[x][5]+=f[i][5];
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	te=read(),T=read();
	while(T--){
		n=read();d=read();ans=0;
		for(int i=1;i<=n;++i)a[i]=read2();//a1<a2<...<an
		for(int i=1;i<=n;){
			int j=i;
			while(j<n&&a[j+1]-a[j]<=d)++j;
			solve(i,j);i=j+1;
		}
		write(ans);pc('\n');
	}
	final_write();
	return 0;
}
