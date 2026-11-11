#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dep(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
template<typename T> void read(T&x){x=0;T f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();x*=f;}
template<typename T1,typename ...T2> void read(T1&x,T2&... y){read(x),read(y...);}
const int N=2e6+15;

int n,d;
int a[N],b[N],f[N],g[N];

namespace sub3{
	void solve(){
		read(n,d);
		rep(i,1,n) read(a[i]),f[i]=g[i]=0;
		int r=0;
		rep(i,1,n){
			if(r<i) r=i;
			while(r<n&&a[r+1]-a[i]<=d) r++;
			b[i]=r;
		}
		vector<int> x,y;
		int ans=0;
		rep(i,1,n){
			x.push_back(i);
			rep(j,1,n) f[j]=g[j]=0;
			f[i]=g[i]=1;
			while(!x.empty()){
				for(auto u:x){
//					cerr<<u<<' ';
					dep(j,b[u],u+1){
						if(f[j]>2||g[j]) break;
						if(!f[j]) y.push_back(j);
						f[j]+=f[u];
					}
				}
//				cerr<<'\n';
				x.clear();
				for(auto u:y){if(f[u]<=2) x.push_back(u);g[u]=1;}
				y.clear();
			}
//			rep(j,1,n) cerr<<f[j]<<" \n"[j==n];
			rep(j,1,n) if(f[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
}

namespace sub4{
	void solve(){
		read(n,d);
		rep(i,1,n) read(a[i]);
		if(a[3]-a[1]>d){cout<<0<<'\n';return ;}
		int x=0;
		rep(i,2,n){if(a[i]-a[1]>d) break;x=i-1;}
		cout<<max(n-x*2+1,0ll)<<'\n';
	}
}

void solve(){
	read(n,d);
	rep(i,1,n) read(a[i]),f[i]=g[i]=0;
	int r=0;
	rep(i,1,n){
		if(r<i) r=i;
		while(r<n&&a[r+1]-a[i]<=d) r++;
		b[i]=r;
	}
	int ans=0;
	dep(i,n,1){
		if(b[i]==b[i+1]) f[i+1]=0;
		int z=b[i],y=z-1,x=y-1;
		f[i]=f[b[i]]+1;
		if(b[y]<b[z]-1||z==i+1) g[i]+=g[z];
		if(y<=i) continue;
		int r=b[y],l=b[x];
		g[i]+=r-l;
		if(b[z]==b[y]&&b[y]!=b[x]) g[i]+=f[b[z]];
	}
//	rep(i,1,n) cout<<a[i]<<' '<<b[i]<<' '<<f[i]<<' '<<g[i]<<'\n';
	rep(i,1,n) ans+=g[i];
	cout<<ans<<'\n';
}

#define NAME "migrate"

signed main(){
#ifdef NAME
	freopen(NAME".in","r",stdin);
	freopen(NAME".out","w",stdout);
#endif
	int c,_;read(c,_);
	if(c==11||c==12){while(_--) sub4::solve();}
	else if(c<=10) while(_--) sub3::solve();
	else while(_--) solve();
	return 0;
}
/*
上厕所*1 15：12
长度指的是经过岛屿数量
感知了一下条件
可能是 \sum[a_{i+2} - a_i \le d]=2
现在我要求的是以 i 为开头有多少只有一种方案的情况
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*2 16:19

猜一下，处理有问题的是前面相同后面不同？
*/