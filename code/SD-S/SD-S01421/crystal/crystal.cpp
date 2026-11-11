#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
const int inf=1e18;
const int mod=998244353;
int n,m;
int a[N];
int ans,cnt=1,k;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=2;
	while(r<=n){
		int c=a[r]-a[r-1];
		k+=c*cnt;
		cnt++;
		while(k>m){
			k-=a[r]-a[l];
			cnt--;
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;

	return 0;
}
