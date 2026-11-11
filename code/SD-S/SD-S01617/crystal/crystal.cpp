#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6+10;
ll maxx,n,m,a[N],sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,r=1;
	while(r<=n&&l<=n){
		while(sum>m) sum-=a[r]-a[l],l++;
		maxx=max(maxx,r-l+1);
		r++;
		sum+=(r-l)*(a[r]-a[r-1]);
	}
	cout<<maxx;
	return 0;
}
