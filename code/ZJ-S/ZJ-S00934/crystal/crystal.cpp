#include<bits/stdc++.h>
#define int long long
#define gc getchar
#define pc putchar
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll=long long;using db=double;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char ch=gc();
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=gc();
		}
		while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
		return x*f;
	}
	inline void write(int x){
		if(x<0) pc('-'),x=-x;
		if(x>9) write(x/10);
		pc(x%10+'0');
	}
}using namespace IO;
const int N=5e5+10;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1,l=1;
	for(int i=1;i<=n;i++){
		while(l<i&&sum[i]-sum[l-1]+m<(i-l+1)*a[i]) l++;
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}