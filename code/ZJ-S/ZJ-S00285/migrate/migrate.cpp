#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t, n, d, x[2000005], ci[2000005], cnt[2000005];
void solve(){
	cin >> n >> d;
	for(ll i=1; i<=n; i++)cin >> x[i];
	ll sum=0;
	for(ll xx=1; xx<=n; xx++){
		for(ll i=1; i<=n; i++)ci[i]=cnt[i]=0;
//		cout<<xx<<'\n';
		for(ll i=xx; i<=n; i++){
//			cout<<t<<':'<<"r:"<<i<<'\n';
			ll idx=upper_bound(x+i, x+1+n, x[i]+d)-x-1;
			ci[idx+1]=1;
			if(i==idx)break;
			i=idx-1;
			
		}
		for(ll i=xx; i>=1; i--){
//			cout<<t<<':'<<"l:"<<i<<'\n';
			ll idx=lower_bound(x, x+i, x[i]-d)-x;
			ci[idx-1]=1;
			if(i==idx)break;
			i=idx+1;
			
		}
		ci[xx+1]=1;ci[xx]=0;ci[xx-1]=1;
		for(ll i=xx+1; i<=n; i++){
			ci[i]+=ci[i-1];
		}
		for(ll i=xx-1; i>=1; i--){
			ci[i]+=ci[i+1];
		}
		queue<pair<ll, ll>>que;
		que.push({xx, 0});
		while(que.size()){
			ll id=que.front().first, w=que.front().second;
			que.pop();cnt[id]++;
			if(w>ci[id]||cnt[id]>2)continue;w++;
			for(ll r=id+1; r<=n; r++){
				if(x[r]-x[id]<=d&&w<=ci[r]){
					que.push({r, w});
				}
			}
			for(ll l=id-1; l>0; l--){
				if(x[id]-x[l]<=d&&w<=ci[l]){
					que.push({l, w});
				}
			}
		}
		for(ll i=1; i<=n; i++){
//			cout<<xx<<':'<<i<<':'<<ci[i]<<','<<cnt[i]<<'\n';
			if(i!=xx&&cnt[i]==2)sum++;
		}
	}
	cout<<sum/2<<'\n';
}
void solve2(){
	cin >> n >> d;
	for(ll i=1; i<=n; i++)cin >> x[i];
	ll ci=d/(x[2]-x[1]);
	if(ci<=1)cout<<"0\n";
	else cout<<max(0ll, n-ci*2+1)<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		if(c<=10)solve();//20·Ö 
		else if(c<=12)solve2();//10·Ö 
	}
	return 0;
}
