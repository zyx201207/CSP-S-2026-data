#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pir;
const int inf=INT_MAX;
ll n,a[500005];
ull m,s[500005],ss[500005];
ull getv(int l,int r){
	return s[r]-s[l]-(l==r?0:l-1)*(a[r]-a[l]);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[0]=s[1]=ss[0]=ss[1]=0;
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(ull)(i-1)*(a[i]-a[i-1]);
		ss[i]=ss[i-1]+(a[i]-a[i-1]);
	}
	int maxn=1,l=1;
	ull sum;
	for(int r=2;r<=n;r++){
		sum=getv(l,r);
		while(sum>m&&l<r){
			sum=getv(++l,r);
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
}
