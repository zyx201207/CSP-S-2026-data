#include <bits/stdc++.h>
using namespace std;
#define int long long
#define CK cerr<<"\n"<<1.0*fabs(&ED-&ST)/1024/1024<<"MB\n";
bool ST;
const int N=2000010,INF=1e17;
int C,T,n,d,a[N],nt[N],su[N],ans,ss[N];
bool ED;
signed main(){
//	freopen("migrate4.in","r",stdin);
//	freopen("migrate.out","w",stdout);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	for(int MF=1;MF<=T;++MF){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		a[n+1]=INF;
		for(int i=1;i<=n;++i){
			nt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			if(nt[i]==i) continue;
			su[nt[i]]+=su[i]+1;
		}
		for(int i=n;i>=1;--i){
			int k=lower_bound(a+1,a+n+1,a[i]-d)-a;
			if(k==i) continue;
			++ss[k];
		}
		for(int i=3;i<=n;++i){
			if(su[i]==0) continue;
			if(nt[i-1]-nt[i-2]>0&&nt[i-1]>i){
				ans+=su[i]*(nt[i-1]-nt[i-2]);
//				cout<<"c1: "<<i<<" : "<<ans<<'\n';
				if(nt[i-1]==nt[i]&&nt[i-2]!=nt[i]){
					int nn=nt[i];
					while(nn<=n){
						ans+=su[i]*(nt[nn]-nt[nn-1]);
						if(nt[nn]==nt[nn-1]) break;
						nn=nt[nn];
					}
//					ans+=su[i]*ss[nt[i]];
				}
				int nn=nt[i];
				if(i==nt[i]) continue;
				while(nn<=n){
					su[nn]-=su[i];
					if(nn==nt[nn]) break;
					nn=nt[nn];
				}
//				su[nt[i]]-=su[i];
//				cout<<"for: "<<i<<" : "<<ans<<'\n';
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;++i){
			su[i]=ss[i]=0;
		}
	}
	CK
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
*/