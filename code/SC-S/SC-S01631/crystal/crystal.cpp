#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<int> a(n+1,0),pre(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++)
		pre[i]=a[i]+pre[i-1];
	for(int l=1,r=1;l<=n;l++){
		while(r<=n){
			int s=pre[r]-pre[l-1];
			if((r-l+1)*a[r]-s<=m)
				ans=max(ans,r-l+1);
			else
				break;
			r++;
		}
	}
	cout<<ans;
}