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
}void fre(){freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);}
int ca;
namespace WinterAwOO{
	int n,d,a[2000010],f[310][310],s[310][310];
	bool g[310][310];
	signed main(int ID){
		n=read();d=read();
		rep1(i,1,n)a[i]=read();
		if(n==1){
			puts("0");
			return 0;
		}if(ca==11||ca==12){
			int t=d/(a[2]-a[1]);
			if(t<2){
				puts("0");
				return 0;
			}writeln(max(n-t*2+1,0));
			return 0;
		}if(ca==13||ca==14){
			int mid=0,r1,r2,sum=0;
			rep1(i,1,n)
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					mid=i;
					break;
				}
			if(mid==1){
				puts("0");
				return 0;
			}r1=r2=mid;
			if(mid>2){
				rep2(i,n,mid+1)
					if(a[i]-a[mid-2]<=d){
						r1=i;
						break;
					}
			}if(mid>1){
				rep2(i,n,mid+1)
					if(a[i]-a[mid-1]<=d){
						r2=i;
						break;
					}
			}rep1(i,1,mid-1)
				if(a[mid+1]-a[i]<=d){
					if(a[mid+2]-a[i]>d)sum+=n-r2;
				}else{
					sum+=r2-r1;
				}
			writeln(sum);
			return 0;
		}rep1(i,1,n)
			rep1(j,1,n)f[i][j]=LLONG_MAX,s[i][j]=0;
		rep1(i,1,n)f[i][i]=0,s[i][i]=1;
		rep1(i,1,n-1)
			rep1(j,i+1,n)
				if(a[j]-a[i]<=d)f[i][j]=f[j][i]=s[i][j]=s[j][i]=1;
		rep1(i,1,n)
			rep1(j,1,n)
				if(i!=j)
					rep1(k,1,n)
						if(i!=k&&j!=k&&s[i][k]&&s[k][j])
							if(f[i][j]==f[i][k]+f[k][j]){
								s[i][j]+=s[i][k]*s[k][j];
							}else if(f[i][j]>f[i][k]+f[k][j]){
								f[i][j]=f[i][k]+f[k][j];
								s[i][j]=s[i][k]*s[k][j];
							}
		int sum=0;
		rep1(i,1,n-1)
			rep1(j,i+1,n)sum+=(s[i][j]==2);
		writeln(sum);
		return 0;
	}
}signed main(){
	fre();
	ca=read();
	int TTT=1;
	TTT=read();
	rep1(ttt,1,TTT)WinterAwOO::main(ttt);
	return 0;
}//40