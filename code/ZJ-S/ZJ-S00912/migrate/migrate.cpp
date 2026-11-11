#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000006,B=31;
int C,T,n,d,a[N],ans;
int fl[N],fr[N];
//int cntl[N],cntr[N];

void solve(){
	ans=0;
	cin>>n>>d;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	fl[1]=1;
	int l=1,dis=0;
	for (int r=2; r<=n; r++){
		dis+=a[r]-a[r-1];
		while (dis>d){
//			cerr<<l<<" -> "<<r<<"  is "<<dis<<'\n';
			fr[l]=r-1;
			dis-=a[l+1]-a[l];
			l++;
		}
		fl[r]=l;
	}
	for (int i=l; i<n; i++) fr[i]=n;
	fr[n]=n;
	
	for (int i=1; i<=n; i++){
		for (int j=i; j<=n; j++){
			int p1=i,p2=j;
			while (fr[p1]<j && fr[p1]!=p1) p1=fr[p1];
			if (p1==i || fr[p1]==p1) continue;
			bool flag=0;
			if (fl[p2]==p1) continue;
			while (fl[p2]>i && fl[p2]!=p2){
				p2=fl[p2];
				if (p2!=p1-1 && p2!=p1) flag=1;
				p1=fl[p1];
			}
			if (flag==0 || fl[p2]==p2) ans++;
		}
	}
	cout<<ans<<'\n';
//	for (int i=1; i<=n; i++){
//		cntl[i]=cntl[fl[i]]+1;
//	}
//	for (int i=n; i>=1; i--){
//		cntr[i]=cntr[fr[i]]+1;
//	}
//	
//	for (int i=1; i<=n; i++) cerr<<a[i]<<' '; cout<<'\n';
//	cerr<<"fly left:  "; for (int i=1; i<=n; i++) cerr<<fl[i]<<' '; cout<<'\n';
//	cerr<<"fly right:  "; for (int i=1; i<=n; i++) cerr<<fr[i]<<' '; cout<<'\n';
//	cerr<<"count left:  "; for (int i=1; i<=n; i++) cerr<<cntl[i]<<' '; cout<<'\n';
//	cerr<<"count right:  "; for (int i=1; i<=n; i++) cerr<<cntr[i]<<' '; cout<<'\n';
//	
//	for (int i=1; i<=n; i++){
//		if (fr[i]<=i+1 || fr[fr[i]-1]==fr[i]) continue;
//		ans+=cntr[fr[i]-1] * cntl[i];
//	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while (T--) solve();
	return 0;
}