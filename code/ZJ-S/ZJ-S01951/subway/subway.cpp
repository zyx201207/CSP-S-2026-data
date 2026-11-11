#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep1(i,x,y) for(int i=(x);i<=(y);i++)
#define rep2(i,x,y) for(int i=(x);i>=(y);i--)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define sp putchar(' ')
#define ln putchar('\n')
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')
int read(){
	char ch=getchar();
	bool p=0;
	int s=0;
	while(ch<'0'||ch>'9'){
		p=(ch=='-'?1:p);
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+(ch^'0');
		ch=getchar();
	}return p?-s:s;
}void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}if(x>9)write(x/10);
	putchar(x%10|48);
}void fre(){freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);}
namespace WinterAwOO{
	int n,m,q,w[500010],f[510][510],a[500010][30],l[500010],t[500010][30];
	signed main(int ID){
		read();n=read();m=read();read();q=read();
		rep1(i,1,m)w[i]=read();
		rep1(i,1,n){
			int k=read();
			rep1(j,1,k){
				int x=read(),y=read();
				a[x][++l[x]]=i;
				t[x][l[x]]=y;
			}
		}rep1(i,1,n)
			rep1(j,1,n)f[i][j]=LLONG_MAX;
		rep1(i,1,n)f[i][i]=0;
		rep1(i,1,m)
			rep1(j,1,l[i]-1)
				rep1(k,j+1,l[i])f[a[i][k]][a[i][j]]=f[a[i][j]][a[i][k]]=min(f[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
		rep1(i,1,n)
			rep1(j,1,n)
				if(i!=j)
					rep1(k,1,n)
						if(i!=k&&j!=k&&f[i][k]<LLONG_MAX&&f[k][j]<LLONG_MAX)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		rep1(i,1,q){
			int x=read(),y=read(),minn=LLONG_MAX;
			rep1(j,1,l[x])
				rep1(k,1,l[y])minn=min(minn,f[a[x][j]][a[y][k]]+t[x][j]+t[y][k]);
			writeln(minn+w[x]+w[y]);
		}
		return 0;
	}
}signed main(){
	fre();
	int TTT=1;
//	TTT=read();
	rep1(ttt,1,TTT)WinterAwOO::main(ttt);
	return 0;
}//100