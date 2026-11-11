#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,maxn=1;
long long m,a[N],s[N];
//static inline void read(int &x){
//	x=0;
//	char c=getchar();
//	int f=1;
//	for(;c<'0'||c>'9';c=getchar()){
//		if(c=='-')f=-1; 
//	}for(;c>='0'&&c<='9';c=getchar()){
//		x=(x<<1)+(x<<3)+c-'0';
//	}x*=f;
//}static inline void write(int x){
//	if(x<0){
//		putchar('-');
//		x=-x;
//	}if(x>9)write(x/10);
//	putchar(x%10+'0');
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1,less<long long>());
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}for(int i=2;i<=n;i++){
		long long sum=1ll*(i-1)*a[i];
		sum-=s[i-1];
		if(sum<m){
			maxn=max(maxn,i);
			continue;
		}int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(l+1==r){
				if(1ll*(i-l)*a[i]-(s[i-1]-s[l-1])<=m){
					break;
				}else{
					l=r;
					break;
				}
			}if(1ll*(i-mid)*a[i]-(s[i-1]-s[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		
//		cout<<i<<' '<<l<<'\n';
		
		if(1ll*(i-l)*a[i]-(s[i-1]-s[l-1])<=m){
			maxn=max(maxn,i-l+1);
		}
	}printf("%d",maxn);
	
	
	return 0;
	
	
}//while(1)rp++;