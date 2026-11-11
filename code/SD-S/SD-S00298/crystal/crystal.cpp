#include<bits/stdc++.h>
#define int long long
using namespace std;
const int xx=1e6+5e2;
const int mod=998244353;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int n,m;
int a[xx];
int sum[xx];
void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int ans=1;
	int l=1;
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		while(l<=i&&(i-l)*a[i]-(sum[i-1]-sum[l-1])>m){
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
}

