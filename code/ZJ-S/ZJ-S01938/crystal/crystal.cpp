#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sc(n) scanf("%lld",&n)
#define scan(n,m) scanf("%lld%lld",&n,&m)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define print(ans) printf("%lld ",ans)
#define put(ans) printf("%lld\n",ans)
#define ed puts("")
#define pb(x) push_back(x)
const int N=5e5+100;
int a[N],b[N],c[N],d[N];
int n,m,k,t,ans,cnt,tmp,x,y;
vector<int> g[N];


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	sc(n);sc(m);
	rep(i,1,n){
		sc(a[i]);
	}
	sort(a+1,a+n+1);
	rep(i,1,n) b[i]=b[i-1]+a[i];
	int now=a[1];
	ans=1;
	int l=1;
	rep(r,1,n){
		while(l<r&&(r-l+1)*a[r]-(b[r]-b[l-1])>m){
			++l;
		}
		
		ans=max(ans,r-l+1);
	}
	put(ans);
	
	
	
	
	
	
	
	return 0;
}
