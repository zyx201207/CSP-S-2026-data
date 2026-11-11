#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
using namespace std;
const int N=5e5+10;

int n,m,a[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	int L=1,res=0;
	int sum=0;
	rep(i,1,n) {
		sum+=(a[i]-a[i-1])*(i-1-L+1);
		while (sum>m) {
			sum-=(a[i]-a[L]);
			L++;
		}
		res=max(res,i-L+1);
	}
	cout<<res<<endl;
	return 0;
}