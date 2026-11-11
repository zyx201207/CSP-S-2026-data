#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

typedef long long ll;
const ll MAX=5e5+5;
ll n,m;
ll a[MAX];

bool cmp(ll x,ll y){
	if(x!=y){
		return x<y;
	}
	else return false;
}

int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fastio
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	for(int l=1;l<=n;l++){
		ll cnt=1;
		ll mm=m;
		ll i=l;		
		while(mm>0){
			if(i==n)break;
			ll cha=a[i+1]-a[i];
			mm=mm-cha*cnt;
			cnt++;			
			i++;
		}		
		if(mm<0)cnt--;
		for(int j=i;j<=n;j++){
			if(i<=n&&a[j]==a[j+1]){
				cnt++;				
			}
			else break;
		}	
		if(cnt>ans)ans=cnt;
	}
	cout<<ans;
	return 0;
}


