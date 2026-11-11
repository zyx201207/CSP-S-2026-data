#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll C,T;
	cin>>C>>T;
	while(T--){
		ll n,d,x[2005]={},step[2005]={},ans=0,cnt[2005]={};
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		queue<ll> q;
		q.push(x[1]);
		step[x[1]]=0;
		while(!q.empty()){
			ll dx=q.front();
			q.pop();
			for(ll i=1;i<=d;i++){
				if(i+dx<=x[n]){
					if(step[dx+i]!=0 && step[dx]+1>step[dx+i]) continue;
					q.push(dx+i);
					step[dx+i]=step[dx]+1;
					cnt[dx+i]++;
				}else break;
			}
		}
		for(ll i=1;i<=x[n];i++) if(cnt[i]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}