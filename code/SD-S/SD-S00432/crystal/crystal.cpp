#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i=b;i>=a;i--)
#define fread freopen("crystal.in","r",stdin)
#define fwrite freopen("crystal.out","w",stdout)
#define readi read<int>()
#define readl read<ll>()
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define inf 0x3f3f3f 
using namespace std;
typedef long long ll;

template<typename T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
template<typename T>
inline void print(T x){
	if(x<0){putchar('-');x*=-1;}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}


const int xx=5e5+5;
ll n,m;
ll a[xx];
ll d[xx];
ll sum[xx];

int main(){
	fread;
	fwrite;
	n=readl,m=readl;
	rep(i,1,n){
		a[i]=readl;
//		print(a[i]);
//		putchar('\n');
	}
	sum[0]=d[1]=0;
	a[0]=a[1]-1;
	int tmp=0;
	rep(i,2,n){
		if(a[i]-a[i-1]>=0) d[i]=a[i]-a[i-1];
		else d[i]=a[i-1]-a[i];
		if(a[i]==a[i+1] && a[tmp]!=a[i]) tmp=i-1;
		if(a[i]==a[i-1] && a[i]<a[tmp]) d[i]=d[i-1];
	}
	sum[1]=d[1];
	rep(i,2,n){
		sum[i]=sum[i-1]+d[i]; 
	}
//	rep(i,1,n){
//		print(d[i]);
//		putchar(' ');
//	}
//	putchar('\n');
//	putchar('\n');
	ll t=d[1];
	int l=1;
	ll ans=1,siz=1;
	rep(r,2,n){
		if(t+d[r]*(r-l)<=m){
			siz++;
			t=t+d[r]*(r-l);
//			cout<<l<<" "<<r<<" "<<t<<"\n";
			ans=max(ans,siz);			
		}else{
			ll tmp=t+d[r]*(r-l);
			siz++;
			if(d[r]>m){
				siz=1;
				t=0;
				l=r;
//				print(t);
//				putchar(' ');
				continue;
			}
			rep(i,l+1,r-1){
				tmp=tmp-sum[r]+sum[i-1];
				siz--;
				bool pd=false;
				if(tmp<=m){
					t=tmp;
					ans=max(ans,siz);
					l=i;
					pd=true;
					break;
				}
				if(!pd && i==r-1){
					siz=1;
					t=0;
					l=r;
					break;
				}				
			}
			t=tmp;
		}
//		cout<<l<<" "<<r<<"\n";
//		print(t);
//		putchar(' ');
	}
//	putchar('\n');
	print(ans);
//	putchar('\n');
	return 0;
}
/*
5 7
1 3 1 4 5
2 
*/
