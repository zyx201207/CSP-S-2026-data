#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=6e5+5;
ll n,m,a[N],KEI[N],ARIS[N],now=0,ans;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		KEI[i]=a[i]-a[i-1];
	}
	KEI[1]=0;
	ll now=0,las=0;
	ARIS[0]=0;
	for(ll i=1;i<=n;i++){
		ARIS[i]=ARIS[i-1]+(i-1)*KEI[i];
		while(ARIS[i]-ARIS[las]-las*(a[i]-a[las])>m){
			las++;
		} 
		now=ARIS[i]-ARIS[las]-las*(a[i]-a[las]);
		if(now<=m){
			ans=max(ans,i-las);
		}
	}
	cout<<ans;
	return 0;
}/*
再见了，王女 
*/
