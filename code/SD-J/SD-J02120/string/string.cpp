#include<bits/stdc++.h>
#define open(x) string fn=x;freopen((fn+".in").c_str(),"r",stdin);freopen((fn+".out").c_str(),"w",stdout);
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(s) s.begin(),s.end()
#define endl '\n'
using namespace std;
using ll=long long;
vector<pair<ll,char> >a;
signed main(){
	open("string");
	io;
	ll n;
	cin>>n;
	string s="";
	for(ll i=1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
	}
//	ll ans=0;
//	ll num=0;
//	ll ls=0;
//	for(ll i=1,j=len;num<=m/2;i++){
//		num+=a[i].first;
//		while(ls<=num){
//			cout<<a[i].first<<' '<<a[i].second<<"  "<<a[j].first<<' '<<a[j].second<<endl;
//			if(a[i].second!=a[j].second){
//				ans+=min(a[i].first,a[j].first);
//				cout<<ans<<endl;
//				a[i+1].first+=(a[i].first-a[j].first);
//			}
//			ls+=a[j].first;
//		}
//	}
	ll ans=0;
	int m=s.size()/2;
	for(int i=0,j=s.size()-1;i<m;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

6
1 a
1 a
1 a
1 b
1 b
1 b

2
2 a
3 b

4
2 a
3 b
2 a
3 b

*/
