#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(z);x>=(z);x--)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvi vector<vi>
#define eb emplace_back
#define emp emplace
#define pob pop_back
#define beg begin
#define all(x) beg(x),end(x)
#define allt(x,y,z) beg(x)+y,beg(x)+z
#define ld long double
#define ull unsigned long long
#define y1 waefefwefidsvbu
#define inf INT_MAX
#define linf LLONG_MAX
#define debug(x) cerr<<" debug at line "<<__LINE__<<": "#x"="<<(x)<<"\n";
//-D_GLIBCXX_DEBUG
/*

*/
int n,m;
#define N 500005
int a[N];
int s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(allt(a,1,n+1));
	int ans=0;
	rep(i,1,n) s[i]=s[i-1]+a[i];
	rep(i,1,n){
		int res=1;
		int l=1;
		int r=i-1;
		for(;l<=r;){
			int mid=(l+r)/2;
			int nd=(a[i]*(i-mid+1))-(s[i]-s[mid-1]);
			if(nd<=m){
				res=i-mid+1;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
}
/*
5 8
-3 -1 2 2 7

*/
