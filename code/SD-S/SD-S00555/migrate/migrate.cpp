#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define to0(x) memset(x,0,sizeof x)
#define to_1(x) memset(x,-1,sizeof x)
#define toinf(x) memset(x,0x3f,sizeof x)
#define pb push_back
#define Debug cout<<"DEBUG\n";
#define Deon(x) cout<<"DEBUG:"<<x<<'\n';
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

ll c,T,n,d,ds[305][305],x[305],as[305][305];

namespace _24pts {
	ll Abs(ll p) {
		return p>0?p:-p;
	}
	void init() {
//		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ds[i][j]=llinf,as[i][j]=0;
		toinf(ds),to0(as);
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>x[i],ds[i][i]=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(x[j]-x[i]<=d) ds[i][j]=1,as[i][j]=1;
			}
		}
	}
	void Floyd() {
		for(int k=1;k<=n;k++) {
			for(int i=1;i<k;i++) {
				for(int j=k+1;j<=n;j++) {
					//dis
					if(ds[i][k]!=llinf&&ds[k][j]!=llinf&&ds[i][j]>ds[i][k]+ds[k][j]) {
						ds[i][j]=ds[i][k]+ds[k][j];
						as[i][j]=0;
					}
//					if(ds[i][k]!=llinf&&ds[k][j]!=llinf&&ds[i][j]==ds[i][k]+ds[k][j]) {
//						ds[i][j]=ds[i][k]+ds[k][j];
//						as[i][j]++;
//					}
				}
			}
		}
		for(int k=1;k<=n;k++) {
			for(int i=1;i<k;i++) {
				for(int j=k+1;j<=n;j++) {
					if(ds[i][k]!=llinf&&ds[k][j]!=llinf&&ds[i][j]==ds[i][k]+ds[k][j]) {
						as[i][j]++;
					}
				}
			}
		}
	}
	void SLV() {
		init();
		Floyd();
		int ct=0;

		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(as[i][j]==2) ct++;
			}
		}
		cout<<ct<<'\n';
	}
	void slv() {
		while(T--) SLV();
	}
}

int main() {
	freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	CLOSE
	cin>>c>>T;
		_24pts::slv();

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

*/
