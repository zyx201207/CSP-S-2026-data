#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=500005;

ll n,m;
ll a[N];
ll cnt[N];
ll b[N];

void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	for(ll i=1;i<=n;i++) cnt[i]=1;
	
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				cnt[i]++;
			}
		}
	}
	
	ll max_cnt=0;
	ll pos=0,num=0;
	for(ll i=1;i<=n;i++){
		max_cnt=max(max_cnt,cnt[i]);
	}
	for(ll i=1;i<=n;i++){
		if(max_cnt==cnt[i]){
			pos=i;
			num=a[i];
			break;
		}
	}
	
	ll sum=0;
	ll ans=0;
	
	if(max_cnt==1||pos==1){
		pos=(1+n)/2;	
		for(ll i=1;i<=n;i++){
			if(sum<=m){
				sum+=a[pos]-a[i];
				ans=i;
			}
			else if(sum<m&&i==pos-1){
				pos++;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		if(sum<=m){
			sum+=a[pos]-a[i];
		}
		if(i>=pos+max_cnt-1){
			ans=i;break;
		}
	}
	
	cout<<ans<<'\n';
	
	
//	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
//	
//	cout<<'\n';
//	cout<<max_cnt<<'\n';
//	cout<<pos<<'\n';
//	cout<<num<<'\n';
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
