#include<bits/stdc++.h>
#define int long long
//UID 1137851
//Oct 31 Today
//Dec 25 ???
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int cur=1,l=1;
	int ans=1;
	while(cur<=n){
		while(a[cur]*(cur-l+1)-sum[cur]+sum[l-1]>m) l++;
		ans=max(cur-l+1,ans);
		cur++;
	}
	cout<<ans;
	return 0;
}

