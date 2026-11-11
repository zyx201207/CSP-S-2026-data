#include<bits/stdc++.h>
#define INF 1e18
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=gc;
	}
	return x*f;
}
const int N=500009;
int n,m;
int a[N];
int s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int ans=0;
	rep(i,1,n){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(((i-mid+1)*a[i]-(s[i]-s[mid-1]))<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

