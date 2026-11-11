#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,mx,mn=1e18,a[N],sum[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i],mx=max(mx,a[i]),mn=min(mn,a[i]);
	for(int i=mn;i<=mx;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<=i&&(i*j-sum[j])<=m)
				ans=max(ans,j);
		}
	}
	cout<<ans;
	return 0;
}                                                                                                        
