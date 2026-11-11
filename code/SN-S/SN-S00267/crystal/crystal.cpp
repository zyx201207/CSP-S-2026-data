#include <bits/stdc++.h>
using namespace std;
#define il inline
#define lld int64_t
namespace DYC{
namespace FastIO{
	const int LEN=1<<20;
	char ibuf[LEN],obuf[LEN],tbuf[20],*p1=ibuf,*p2=ibuf,*p3=obuf;
	il char gc(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,LEN,stdin),p1==p2)?EOF:*p1++;}
	il void flush(){fwrite(obuf,1,p3-obuf,stdout),p3=obuf;}
	il void pc(char x){p3-obuf==LEN?flush():void(),*p3++=x;}
	il void read(auto &x){
		char ch=gc();bool fl=0;x=0;
		while(ch< '0'||ch> '9')fl=ch=='-',ch=gc();
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc();
		fl?x=-x:x;
	}
	il void read(auto &x,auto &...y){read(x),read(y...);}
	il void write(int x){
		short top=0;
		do tbuf[top++]=x%10;while(x/=10);
		while(top)pc(tbuf[--top]|48);
	}
}
using namespace FastIO;

const int N=5e5+5;

int n,ans;
lld m,sum,a[N];
il void main(){
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+1+n);
	for(int r=1,l=1;r<=n;r++){
		for(sum+=a[r];;){
			lld lim=(r-l+1)*a[r];
			if(sum+m>=lim)break;
			sum-=a[l],l++;
		}
		ans=max(ans,r-l+1);
	}
	write(ans);
}}
int main(){DYC::main(),DYC::flush();}
