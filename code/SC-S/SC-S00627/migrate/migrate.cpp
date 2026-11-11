#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11 || c==12){
			ll ans=0;
			ll cha=a[2]-a[1];
			if(d>=2*c){
				ans=n-3;
				ll mx=d/cha;
				mx=mx*2-1;
				if(n>mx) ans+=(n-mx);
			}
			cout<<ans<<endl;
			continue;
		}
		if(c==13 || c==14){
			
		}
		int ans=0;
		vector<pair<ll,ll>>v,nv; // 上个岛，岛数
		for(int i=1;i<n;i++){
			v.push_back({i,1});
			for(int j=i+1;j<=n;j++){
				ll mid=1e9,mic=1;//最小岛数是多少，最小岛数有几个
				for(auto o:v){
					if(a[j]-a[o.first]<=d){
						nv.push_back(o);
						nv.push_back({j,o.second+1});
					}
				}
//				if(i==1){ for(auto o:nv) cout<<o.first<<' '<<o.second<<endl;}
//				cout<<endl;
				for(auto o:nv){
					if(o.first!=j) continue;
					if(o.second<mid) mid=o.second,mic=1;
					else if(o.second==mid) mic++;
				}
				if(mic==2) ans++;
				v=nv;
				nv.clear();
			}
			v.clear();
		}
		cout<<ans<<endl;
	}
	/*1 2 3 4*/
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

*/