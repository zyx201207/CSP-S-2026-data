#include<bits/stdc++.h>
#define int long long
using namespace std;
//多测不清空的是给 我清了
const int N=2000005;
int n,d,a[N],ans;
int f[5005],g[5005];
int solve() {
	//40分 n^2 暴力
	ans=0;
	cin>>n>>d;
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int l=1; l<=n; ++l) {
		memset(f,0x3f,sizeof f);
		memset(g,0,sizeof g);
		f[l]=0,g[l]=1;
		for(int i=l+1,j=l; i<=n; ++i) {
			while(a[i]-a[j]>d) ++j;
			if(j==i) break;
			f[i]=f[j]+1;
			int gg=g[j];
			for(int x=j+1; x<=min(j+2,i-1); ++x) {
				if(f[x]==f[j]) gg+=g[x];
				else break;
			}
			if(gg==1) g[i]=1;
			else if(gg==2) ++ans,g[i]=gg;
			else g[i]=3;
		}
	}
	return ans;
}
int solveA() {
	//8分A性质
	cin>>n>>d;
	for(int i=1; i<=n; ++i) cin>>a[i];
	if(n==1) return 0;
	int c=d/(a[2]-a[1]);
	if(c==0) return 0;
	int l=2*c-1;
	if(l>=1&&l<=n-1&&l/c==1&&l%c) return n-l;
	return 0;
}
int solveB() {
	ans=0;
	//18:21
	//8分B性质，但大概率过不了
	cin>>n>>d;
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int i=1,j=1; i<=n; ++i) {
		while(a[i]-a[j]>d) ++j;
		if(j!=1&&j+2==i) ++ans;
	}
	return ans;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0);
	int c,T=1;
	cin>>c>>T;
	if(c<=10) {
		while(T--) cout<<solve()<<"\n";
	}
	if(c==11||c==12) {
		while(T--) cout<<solveA()<<"\n";
	}
	if(c==13||c==14) {
		while(T--) cout<<solveB()<<"\n";
	}
	return 0;
}

