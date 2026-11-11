#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T,n,d,a[N],ans;

int dpl[N],dpr[N];
int sl[N],sr[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		a[0]=-4'000000'000000'000000ll;
		a[n+1]=4'000000'000000'000000ll;
		
		int l=0,r=0;
		dpl[0]=0;
		for(int i=1;i<=n;++i){
			while(l<i&&a[i]-a[l]>d) ++l;
			while(r<i&&a[i+1]-a[r]>d) ++r;
			dpl[i]=1+r-l;
			if(l<r) dpl[i]+=dpl[l]-1;
//			cout<<l<<' '<<r<<' '<<dpl[i]<<'\n';
		}
//		cout<<'\n';
		l=r=n+1;
		dpr[n+1]=0;
		for(int i=n;i>=1;--i){
			while(l>i&&a[l]-a[i-1]>d) --l;
			while(r>i&&a[r]-a[i]>d) --r;
			dpr[i]=1+r-l;
			if(l<r) dpr[i]+=dpr[r]-1;
//			cout<<l<<' '<<r<<' '<<dpr[i]<<'\n';
		}
//		cout<<'\n';
		l=r=0;
		sl[0]=0;
		for(int i=1;i<=n-1;++i){
			//(a[i],a[i+1])keypoints
			while(l<i&&a[i+1]-a[l]>d) ++l;
			while(r<i&&a[i+2]-a[r]>d) ++r;
			sl[i]=r-l;
			if(l<r&&a[i]-a[l-1]>d) sl[i]+=dpl[l]-1;
		}
		l=r=n+1;
		sr[n+1]=0;
		for(int i=n;i>=2;--i){
			//(a[i-1],a[i])keypoints
			while(l>i&&a[l]-a[i-2]>d) --l;
			while(r>i&&a[r]-a[i-1]>d) --r;
			sr[i]=r-l;
			if(l<r&&a[r+1]-a[i]>d) sr[i]+=dpr[r]-1;
		}
		ans=0;
		for(int i=1;i<=n-1;++i) ans+=sl[i]*sr[i+1];
		cout<<ans<<'\n';
	}
	return 0;
}
//610:1213157
/*
0 1
10 3
0 1 2 3 4 5 6 7 8 9
*/
