#include<bits/stdc++.h>
namespace chuazen{
	#define ufor(i,x,y) for(int i=x;i<=y;i++)
	#define dfor(i,x,y) for(int i=x;i>=y;i--)
	#define N 500005
	char out[100],ch; int tp;
	#define int long long
	#define getchar() (p1==p2&&(p2=(p1=in)+fread(in,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	char in[1<<21],*p1,*p2;
	inline int read(){
		int x=0,f=1; ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
		return x*f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		tp=0;
		do out[++tp]=x%10+'0', x/=10; while(x);
		while(tp)putchar(out[tp--]);
	}
}
using namespace std;
using namespace chuazen;

int n,m,a[N],nd[N];
int l,r,mid,temp,ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	ufor(i,1,n)a[i]=read(); sort(a+1,a+n+1);
	ufor(i,2,n)nd[i]=(a[i]-a[i-1])*(i-1)+nd[i-1];
	ufor(i,1,n){
		l=1,r=i;
		while(l<r){
			mid=(l+r)>>1;
			temp=nd[i]-nd[mid]-(a[i]-a[mid])*(mid-1);
			if(temp<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	write(ans);
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
