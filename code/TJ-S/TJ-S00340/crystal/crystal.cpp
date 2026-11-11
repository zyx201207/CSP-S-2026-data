#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using xll=__int128;
const int mxn=5e5+7;
ll as[mxn],n,m;
namespace C1{
	xll summ;
	deque<ll> oks;
	void run(){
		sort(as+1,as+1+n);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll nowv=as[i],dir=nowv-as[i-1];
			summ+=(xll)oks.size()*dir;
			oks.push_back(i);
			while(!oks.empty()&&summ>(xll)m){
				int popid=oks.front();
				oks.pop_front();
				summ-=(nowv-as[popid]);
			}
			ans=max(ans,(ll)oks.size());
		}
		cout<<ans<<endl;
	}
}
int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>as[i];
	}
	C1::run();
	return 0;
}
