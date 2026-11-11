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
const int N=1e6+100;
int a[N],b[N];
int n,m,k,t,ans,cnt,tmp,x,y,d;
vector<int> g[N];
int gtnxt(int i,int l,int r){
	int ans=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]-a[i]<=d){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int get(int l,int r){
	int ans=0;
	ans+=upper_bound(a,a+n+2,r)-a-1;
	ans-=upper_bound(a,a+n+2,l-1)-a-1;
	return ans;
	
}
void solve(){
	sc(n);
	sc(d);
	ans=0;
	a[0]=-2e18;
	a[n+1]=2e18;
	rep(i,1,n){
		sc(a[i]);
	}
	rep(i,1,n-1) b[i]=gtnxt(i,i+1,n);
	rep(i,1,n-1){
		int flg=0,lflg=0;
		int now=i,lst=i;
		now=b[now];
		while(now!=n){
			rep(j,now+1,b[now]){
//				put(lst);
//				put(b[now]);
				cnt=get(a[lst],a[lst]+d)+get(a[j]-d,a[j])-get(a[lst],a[j]);
				//put(cnt);
				
				
				if(cnt==1&&lflg==1) ans++;
				else if(cnt==2){
					if(lflg==1){
						if(j==b[now]) flg=2;
						continue;
					}
					ans++;
					if(j==b[now])flg=1;
//					print(i);
//					print(j);ed;
				}
				else if(cnt>2){
					if(j==b[now])flg=2;
				}
			}
			if(flg>1){
				break;
			}
			lst=now;
			lflg=max(lflg,flg);
			now=b[now];
		}
	}
	
	
	
	put(ans);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	sc(T),sc(T);
	while(T--){
		solve();
	}
	
	
	
	
	
	
	
	return 0;
}
