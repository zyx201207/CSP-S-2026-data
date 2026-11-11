#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=998244353,INF=1e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
int a[N],sum[N];
int n,m;
bool check(int x){
	rep(i,1,n-x+1){
		int now=sum[i+x-1]-sum[i-1];
		if(a[i+x-1]*x-now<=m)	return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,n)	cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)	sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else  r=mid-1;
	}
	cout<<ans<<endl;
}