#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
namespace IO{
	char *p1,*p2,buf[100000];
	#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
	template<class T>
	inline void read(T &x){
		int f=1,ch=nc();x=0;
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=nc();
		}
		while(isdigit(ch)){
			x=(x<<3)+(x<<1)+ch-'0';
			ch=nc();
		}
		x*=f;
	}
	template<class T>
	void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
};
using namespace IO;
constexpr int N=2000005,INF=LLONG_MAX;
int C,T,n,d,ans,x[N],nxt[N],g[N],f[N][2];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(C),read(T);
	while(T--){
		read(n),read(d);
		for(int i=1;i<=n;i++){
			read(x[i]);
		}
		x[n+1]=INF;
		for(int i=1;i<=n;i++){
			nxt[i]=upper_bound(x+1,x+2+n,x[i]+d)-x-1;
			f[i][0]=f[i][1]=g[i]=0;
		}
		for(int i=n;i>1;i--){
			int D=nxt[i]-nxt[i-1];
			g[i]=D+(D>0?g[nxt[i]]:0);
			f[i][0]=(D>1?f[nxt[i]][1]:D>0?f[nxt[i]][0]:0);
			if(i>2){
				int D2=nxt[i-1]-nxt[i-2];
				f[i][1]=f[i][0]+D2+(D2>0&&D<1?g[nxt[i-1]]:0);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(nxt[i]==i) continue;
			else if(nxt[i]>i+1){
				ans+=f[nxt[i]][1];
			}else ans+=f[nxt[i]][0];
		}
		write(ans);
		puts("");
	}
}

