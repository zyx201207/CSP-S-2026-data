// code by Umbrella.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define mkp make_pair
namespace Umbrella{
	int n,d;
	int a[1000005];
	void solve(){
		cin>>n>>d;
		rep(i,1,n){
			cin>>a[i];
		}
		int ans=0;
		rep(i,1,n-3){
			int f1=(a[i+2]-a[i]<=d)&&(a[i+3]-a[i+2]<=d);
			int f2=(a[i+1]-a[i]<=d)&&(a[i+3]-a[i+1]<=d);
			if(f1&&f2){
				int w=1;
				rep(j,i+4,n){
					if(a[j]-a[j-1]<=d&&a[j]-a[j-2]>d) w++;
					else break;
				}
				per(j,i,2){
					if(a[j]-a[j-1]<=d&&a[j]-a[j-2]>d) w++;
					else break;
				}
				ans+=w;
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,_T=1;
	cin>>c>>_T;
	while(_T--){
		Umbrella::solve();
	}
	return 0;
}
