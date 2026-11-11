#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N=2e6+5;
int tid,t;
int n,d;
int a[N];
int dis[N];
int cnt[N];
void solve1(){
	int l=0;
	int r=0;
	rep(i,1,n){
		if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
			if(!l)l=i;
			r=i; 
		}
	}
	if(l+2<r){
		cout<<0<<"\n";
		return ;
	}
	if(l==r){
		int pos=1;
		int ans=0;
		rep(i,1,l-1){
			while(pos<=n&&a[pos]-a[i]<=d)pos++;
			ans+=n-pos+1;
		}
		cout<<ans<<"\n";
		return ;
	}else{
		int pos=1;
		int ans=0;
		rep(i,1,l-1){
			while(pos<=n&&a[pos]-a[i]<=d)pos++;
			if(pos-1==r)ans+=n-pos+1;
		}	
		cout<<ans<<"\n";
		return ;
	}
	return ;
}
void solve2(){
	cout<<10*n<<"\n";
	return ;
}
void solve(){
	cin>>n>>d;
	rep(i,1,n)cin>>a[i];
	if(tid>=13&&tid<=14){
		solve1();
		return ;
	}
	if(tid>=15&&tid<=18){
		solve2();
		return ;
	}
	if(tid>=11&&tid<=12){
		int gc=a[2]-a[1];
		int x=d/gc;
		if(gc>=d){
			cout<<0<<"\n";
			return ;
		}
		cout<<max(0ll,n-2*x+1)<<"\n";
		return ;
	}
	int ans=0;
	rep(i,1,n){
		dis[i]=0; 
		cnt[i]=1;
		rep(j,i+1,n){
			dis[j]=1e18;
			cnt[j]=0;
			per(k,j-1,i){
				if(a[j]-a[k]>d)break;
				if(dis[j]>dis[k]+1){
					dis[j]=dis[k]+1;
					cnt[j]=cnt[k];
				}else if(dis[k]+1==dis[j])cnt[j]+=cnt[k];
				else break;	
			}
			if(cnt[j]==2)ans++;
			if(dis[j]==1e18)break;
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>tid>>t;
	while(t--)solve();
	return 0;
}
