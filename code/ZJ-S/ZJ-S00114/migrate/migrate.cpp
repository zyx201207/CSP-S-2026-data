#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
const ll inf=4e18;
int n;ll d;
ll x[N];
namespace solve1{
ll f[N],num[N];

void solve(){
	ll ans=0;
	for(int l=1;l<=n;l++){
		deque<int> dq;dq.push_back(l);
		f[l]=0,num[l]=1;
		ll mn=0,sum=1;
		for(int r=l+1;r<=n;r++){
			while(!dq.empty()&&x[r]-x[dq.front()]>d)sum-=(f[dq.front()]==mn?num[dq.front()]:0ll),dq.pop_front();
			if(dq.empty()||mn!=f[dq.front()]){
				if(dq.empty())mn=inf;
				else{
					int pos=0;mn=f[dq[0]];
					while(pos<dq.size()&&f[dq[pos]]==mn)sum+=num[dq[pos]],pos++;
				}
			}
			f[r]=mn+1,num[r]=sum;
			if(f[r]>=inf)break;
			if(num[r]==2)ans++;
			while(!dq.empty()&&f[dq.back()]>f[r])dq.pop_back();
			dq.push_back(r);
		}
	}
	cout<<ans<<"\n";
}
}
namespace solve2{


void solve(){
	if(n==1){
		cout<<0<<"\n";return;
	}
	ll L=d/(x[2]-x[1]);
	if(L==0){
		cout<<0<<"\n";return;
	}
	ll ans=0;
	for(int len=2*L-1;len<=n;len+=L){
		ans+=max(0,n-len+1);
	}
	cout<<ans<<"\n";
}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=5000)solve1::solve();
		else if(c==11||c==12)solve2::solve();
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17

*/
