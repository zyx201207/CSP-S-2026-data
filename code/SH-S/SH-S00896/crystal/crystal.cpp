#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define FILE(X) freopen(X".in","r",stdin); freopen(X".out","w",stdout);
using namespace std;
const int N=500050;
int n,m;
int a[N];
int sum,cst;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	FILE("crystal");
	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	
	sort(a,a+n);
	sum=0;
	for(int i=0;i<n;i++) {
		sum+=a[i];
		cst=a[i]*(i+1)-sum;
		if(cst>m) {
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
}

