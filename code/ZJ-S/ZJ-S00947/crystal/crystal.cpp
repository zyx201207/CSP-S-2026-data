#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll sum;
ll ans;
ll cnt;
struct rce{
	ll z;
	ll zz;
	ll ans; 
}b[500005];
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++){
		if(a[i]==a[i-1]&&i!=1){
			b[cnt].ans++;
		}
		else{
			b[++cnt].z=a[i];
			b[cnt].zz=b[cnt-1].zz+abs(b[cnt].z-b[cnt-1].z)*(b[cnt-1].ans);
			b[cnt].ans=b[cnt-1].ans+1;
		}
		if(b[cnt].zz<=m) ans=max(b[cnt].ans,ans);
		else{
			while(b[cnt].zz>m&&sum<=i){
				b[cnt].zz-=b[cnt].z-a[++sum];
				b[cnt].ans--;
			}
		}
		if(b[cnt].zz<=m) ans=max(b[cnt].ans,ans);
	}
	for(int i=1; i<=cnt; i++){
		if(b[cnt].zz<=m) ans=max(ans,b[i].ans);
	}
	cout<<ans<<"\n";
	return 0;
}
