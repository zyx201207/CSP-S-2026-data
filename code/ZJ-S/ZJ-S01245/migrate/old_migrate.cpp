#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T,n,d,a[N],ans;

int dpl[N],dpr[N];
int sdpl[N],sdpr[N];
signed main(){
//	freopen("migrate3.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		a[0]=-4'000000'000000'000000ll;
		a[n+1]=4'000000'000000'000000ll;
		
		int l=0,r=0;
		dpl[0]=sdpl[0]=0;
		for(int i=1;i<=n;++i){
			while(l<i&&a[i]-a[l]>d) ++l;
			while(r<i&&a[i+1]-a[r]>d) ++r;
			dpl[i]=1+sdpl[r-1]-sdpl[l-1];
			sdpl[i]=sdpl[i-1]+dpl[i];
			cout<<l<<' '<<r<<' '<<dpl[i]<<'\n';
		}
		cout<<'\n';
		l=r=n+1;
		dpr[n+1]=sdpr[n+1]=0;
		for(int i=n;i>=1;--i){
			while(l>i&&a[l]-a[i-1]>d) --l;
			while(r>i&&a[r]-a[i]>d) --r;
			dpr[i]=1+sdpr[l+1]-sdpr[r+1];
			sdpr[i]=sdpr[i+1]+dpr[i];
			cout<<l<<' '<<r<<' '<<dpr[i]<<'\n';
		}
		cout<<'\n';
		ans=0;
		for(int i=1;i<=n-1;++i){
			//(a[i],a[i+1])keypoints
			int sl=(dpl[i+1]-1);
			if(a[i+2]-a[i]>d&&a[i+1]-a[i]<=d) sl-=dpl[i];
			int sr=(dpr[i]-1);
			if(a[i+1]-a[i-1]>d&&a[i+1]-a[i]<=d) sr-=dpr[i+1];
			ans+=sl*sr;
		}
//		cout<<"----------> ";
		cout<<ans<<'\n';
	}
	return 0;
}
//610:1213157
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
7 6
-10 -5 -1 1 3 5 9
*/
