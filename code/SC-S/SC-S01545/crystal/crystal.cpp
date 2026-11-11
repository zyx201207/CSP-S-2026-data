#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int s[N];
bool check(int x){
	rep(i,x,n){
		int t=x*a[i]-(s[i]-s[i-x]);
		if(t<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	int ans=0;
	int l=0;
	int r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}