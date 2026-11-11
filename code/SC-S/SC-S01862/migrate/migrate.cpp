#include<bits/stdc++.h>
#define fir first
#define sec second
#define int long long
#define pii pair<int,int>
#define tomin(a,b) a=min(a,b)
#define tomax(a,b) a=max(a,b)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define pef(i,s,e) for(int i=s;i>e;i--)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
const int N=2e6+47;
const int inf=1e18;
int c,T,n,d,x[N],L[N],R[N];
int f[5005][5005],g[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		rep(i,1,n)cin>>x[i];
		int r=1;
		rep(l,1,n){
			while(r<n&&x[r+1]-x[l]<=d)r++;
			R[l]=r-l;
		}
		int l=n;
		per(r,n,1){
			while(l>1&&x[r]-x[l-1]<=d)l--;
			L[r]=r-l;
		}
		if(c<=10){
			rep(i,1,n){
				rep(j,1,n){
					f[i][j]=inf;
					g[i][j]=0;
				}
			}
			rep(i,1,n){
				rep(j,1,n){
					if(abs(x[j]-x[i])<=d){
						f[i][j]=1;
						g[i][j]=1;
					}
				}
			}
			rep(mid,1,n){
				rep(i,1,n){
					rep(j,1,n){
						tomin(f[i][j],f[i][mid]+f[mid][j]);
					}
				}
			}
			rep(len,1,n){
				rep(l,1,n-len){
					int r=l+len;
					rep(mid,l+1,r-1){
						if(f[l][mid]!=1)break;
						if(f[l][r]==f[l][mid]+f[mid][r])
						g[l][r]+=g[l][mid]*g[mid][r];
					}
				}
			}
			int ans=0;
			rep(i,1,n){
				rep(j,i+1,n){
					if(g[i][j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
		else if(c<=12){
			int del=x[2]-x[1];
			d/=del;
			int ans=0;
			if(d==2)ans=n-3;
			cout<<ans<<"\n";
		}
	}
}
/*
0 5
5 3
-3 0 2 3 4
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
4 2
1 2 3 4
5 2 
1 2 3 4 5

2
0
1
1
2
*/