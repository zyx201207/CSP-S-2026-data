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
const int N=5e5+5;
int n,m,a[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int r=1,del=0;
	rep(l,1,n){
		del-=(a[r-1]-a[l-1]);
		while(r<n&&del+(r-l+1)*(a[r+1]-a[r])<=m){
			del+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		tomax(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
