#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
const int N=5e5+5;
int c,n,m,d,q,w[N];
vector<int> a[N],t[N];
signed main() {
    cin.tie(0)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	f(i,1,m) cin>>w[i];
	f(i,1,n) {
		int k;
		cin>>k;
		f(j,1,k) cin>>a[j][i]>>t[j][i];
	}
	
    return 0;
}