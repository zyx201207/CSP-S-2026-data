#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans=0;
unsigned ll cf[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cf[1]=0;
	for(int i=2;i<=n;i++) cf[i]=(a[i]-a[i-1])*(i-1)+cf[i-1];
	ll l=1,r=1;
	while(l<n){
		while(cf[r]-cf[l]-(l-1)*(a[r]-a[l])<=m){r++;}
		ans=max(ans,r-l);
		while(cf[r]-cf[l]-(l-1)*(a[r]-a[l])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
