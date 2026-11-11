#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define fi first
#define se second
#define gc getchar
#define pc putchar
#define MS(x,y) memset(x,y,sizeof(x))
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll=long long;using db=double;
const ll INF=1e18;
const int inf=0x3f3f3f3f;
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
const int N=2e6+10;
int n,x[N],d,f[N],q[N],num[N];
inline void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) f[j]=INF,num[j]=0;
		int l=1,r=1;
		q[1]=i,f[i]=0,num[i]=1;
		for(int j=i+1;j<=n;j++){
			while(l<=r&&x[j]-x[q[l]]>d) l++;
			if(l>r) break;
			f[j]=f[q[l]]+1;
			int pos=l,val=f[q[l]];
			while(pos<=r){
				if(f[q[pos]]==f[q[l]]){
					num[j]+=num[q[l]];
					if(num[j]>2) break;
				}
				else break;
				pos++;
			}
			if(num[j]==2) res++;
			while(l<=r&&f[q[r]]>f[j]) r--;
			q[++r]=j;
		}
//		int l=i;
//		f[i]=0,num[i]=1;
//		for(int j=i+1;j<=n;j++){
//			if(x[j]-x[j-1]>d) break;
//			while(l<j&&x[j]-x[l]>d) l++;
//			for(int k=l;k<j;k++) f[j]=min(f[j],f[k]);
//			for(int k=l;k<j;k++) if(f[k]==f[j]) num[j]+=num[k];
//			f[j]++;
//			if(num[j]==2) res++;
//		}
//		puts("");
	}
	write(res),puts("");
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--) solve();
	return 0;
}