#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N],ans,sum[40];
bool vis[N],f[N][50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		ans=a[1];
		for(ll i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,greater<ll>());
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<=30;j++)
			f[i][j+1]=((a[i]>>j)&1);
	ll cnt=0;
	for(ll j=30;j>=1;j--){
		if(cnt==m) break;
		ll x=0,y=0;
		for(ll i=1;i<=n;i++){
			if(f[i][j]){
				if(x==0) x=i;
				else{
					y=i;
					break;
				}
			}
		}
		if(x==0||y==0) continue;
		if(!vis[x]) vis[x]=1,cnt++;
		if(cnt==m) break;
		if(!vis[y]) vis[y]=1,cnt++;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]){
			if(ans==0) ans=a[i];
			else ans=ans&a[i];
		}
	}
//	for(ll i=1;i<=n;i++) cout<<vis[i]<<" ";
//	cout<<"\n";
	cout<<ans;
	return 0;
} 
