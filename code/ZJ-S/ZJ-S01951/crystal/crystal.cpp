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
}void fre(){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);}
namespace WinterAwOO{
	int n,m,a[500010],s[500010],maxn=-1,debug1,debug2,debug3;
	signed main(int ID){
		n=read();m=read();
		rep1(i,1,n)a[i]=read();
		sort(a+1,a+n+1);
		rep1(i,1,n)s[i]=s[i-1]+a[i];
		rep1(i,1,n){
			int l=1,r=i-1,ans=i;
			while(l<=r){
				int mid=l+r>>1;
				if((i-mid)*a[i]-s[i-1]+s[mid-1]<=m){
					ans=mid;
					r=mid-1;
				}else l=mid+1;
			}maxn=max(maxn,i-ans+1);
		}write(maxn);
		return 0;
	}
}signed main(){
	fre();
	int TTT=1;
//	TTT=read();
	rep1(ttt,1,TTT)WinterAwOO::main(ttt);
	return 0;
}//100