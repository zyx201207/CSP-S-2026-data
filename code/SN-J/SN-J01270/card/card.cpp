//yellow or green question,and it runs for O(n),costs memory less than 20MB
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll firstt[500005],nextt[500005];
ll fx[500005];
ll ans[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=m;i++) firstt[i]=n+1;
	for(ll i=n;i>=1;i--){
		nextt[i]=firstt[a[i]];
		firstt[a[i]]=i;
		fx[i]=1;
	}
	for(ll i=1;i<=n;i++){
		if(nextt[i]==n+1){
			fx[i+1]+=fx[i]*1;
			ans[a[i]]+=fx[i];
		}
		else{
			fx[nextt[i]]+=fx[i]*1;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
