#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m;
ll a[500005]; 
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ll ans1=0;
		ll mm=m;
		for(int j=i+1;j<=n;j++){
			ll cha=llabs(a[i]-a[j]);
			if(llabs(a[i]-a[j+1])>=mm&&mm-llabs(a[i]-a[j+1])-cha>=0){
				cha=max(llabs(a[i]-a[j+1]),cha);
				continue;
			}
			else{
				ans1++;
				mm-=cha;
			}
			ans=max(ans,ans1);
		}
	} 
	cout<<ans<<'\n';
	return 0;
}

