#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back

const int mod=998244353;

const int N=500010;

int n,m,l,r,a[N],sum,ans,op;



signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	l=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		op=(i-l+1)*a[i];
		while(op-sum>m){//²»ºÏ·¨ 
			sum-=a[l];
			l++;
			op=(i-l+1)*a[i];
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
