#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;

int n,m,a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,w=0,rt=1;
	while(r<n&&w+(r-l+1)*(a[r+1]-a[r])<=m){
		w+=(r-l+1)*(a[r+1]-a[r]),r++;
	}
	for(;r<=n;w+=(r-l+1)*(a[r+1]-a[r]),r++){
		while(w>m&&l<r)w-=(a[r]-a[l++]);
		rt=max(rt,r-l+1);
	}
	cout<<rt<<'\n';
	return 0;
}
