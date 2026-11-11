#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define foR(i,j,k) for(int i=(j);i>=(k);i--)
#define ull unsigned long long
#define double long double
#define i128 __int128
#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,a[N],pre[N];
bool check(int x){
	int res=1e18+10;
	For(i,x,n)
		res=min(res,a[i]*x-pre[i]+pre[i-x]);
//	cerr<<x<<"!!"<<res<<endl;
	return (res<=m);
}
void solve(){
	cin>>n>>m;
	For(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	For(i,1,n)pre[i]=pre[i-1]+a[i];
	int l=1,r=5e5;
	while(l<r){
//		cerr<<l<<" "<<r<<endl;
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
