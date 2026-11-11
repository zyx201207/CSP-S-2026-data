#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;

int n,d,ans=0,a[N+10],cnt[N+10],dis[N+10];
void init() {
	cin>>n>>d; ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
} bool checkA() {
	for(int i=1;i<=n-2;i++) if(a[i]+a[i+2]!=2*a[i+1]) return 0;
	return 1;
} 
bool check(int x,int y) {
	return a[y]-a[x]<=d;
}
void work() {
	
//	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) cnt[j]=0; dis[i]=0; cnt[i]=1; cnt[i-1]=0;
		for(int j=i+1;j<=n;j++) {
			int l=i,r=j-1,L=-1,R=-1;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(check(mid,j)) L=mid,r=mid-1;
				else l=mid+1;
			} if(L==-1) break;
//			cout<<j<<" "<<L<<endl; 
			dis[j]=dis[L]+1; 
			l=L,r=j-1;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(dis[L]==dis[mid]) R=mid,l=mid+1;
				else r=mid-1;
			} cnt[j]=cnt[R]-cnt[L-1];
			if(cnt[j]==2) ans++;
			cnt[j]+=cnt[j-1];
		} 
	} cout<<ans<<endl;
} void workA() {
//	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++) cnt[0]=0; dis[1]=0; cnt[1]=1; cnt[0]=0;
	for(int j=2;j<=n;j++) {
		int l=1,r=j-1,L=-1,R=-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid,j)) L=mid,r=mid-1;
			else l=mid+1;
		} if(L==-1) break;
//		cout<<j<<" "<<L<<endl; 
		dis[j]=dis[L]+1; 
		l=L,r=j-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(dis[L]==dis[mid]) R=mid,l=mid+1;
			else r=mid-1;
		} cnt[j]=cnt[R]-cnt[L-1];
		if(cnt[j]==2) ans+=(n-j+1);
		cnt[j]+=cnt[j-1];
	} 
	cout<<ans<<endl;
} 
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Test,t; cin>>Test>>t; while(t--) {
		init();
		if(checkA()) workA();
		else work();
	}
	
	return 0;
} 
