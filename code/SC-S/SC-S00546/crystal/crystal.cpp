#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m,a[N],ans=1;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,sumx=0;
	for(int r=1;r<=n;r++){
		sumx+=a[r];
		while((r-l+1)*a[r]-sumx>m){
			sumx-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
