#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,char>>v;
vector<pair<ll,char>>qian;
vector<pair<ll,char>>hou;
vector<pair<ll,char>>houb;
int n;
ll ans=0;
int main(){
	if(n<=2000){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++){
			ll x;
			char y;
			cin>>x>>y;
			for(ll i=1;i<=x;i++){
				v.push_back(y);
			}
		}
		ll m=v.size();
		if(m%2==0){
			for(ll i=0;i<m/2;i++){
				if(v[i]!=v[i+m/2]){
					ans++;
				}
			}
		}else{
			for(ll i=0;i<m/2;i++){
				if(v[i]!=v[i+1+m/2]){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0; 
	}
//	cin>>n;
//	ll m;
//	for(int i=1;i<=n;i++){
//		ll x;
//		char y;
//		cin>>x>>y;
//		v.push_back({x,y});
//		m+=x;
//	}
//	ll half=0;
//	if(m%2==0){
//		for(int i=0;i<v.size();i++){
//			if(half+v[i].first>=(m/2)){
//				qian.push_back({(m/2)-half,v[i].second});
//				hou.push_back({v[i].first-((m/2)-half),v[i].second});
//				half=i+1;
//				break;
//			}else{
//				qian.push_back(v[i]);
//			}
//		}
//	
//		for(int i=half;i<=v.size();i++){
//			hou.push_back(v[i]);
//		}
//		for(int i=0;i<=hou.size();i++){
//			if(hou[i].first<qian[qian.size()-i].first){
//				qian[qian.size()-i].first-=hou[i].first;
//				qian.push_back({hou[i].first,qian[qian.size()-i].second});
//				houb.push_back(hou[i]);
//			}else if(hou[i].first==qian[qian.size()-i].first){
//				houb.push_back(hou[i]);
//				continue;
//			}else{
//				houb.push_back({qian[qian.size()-i].first,hou[i].second});
//				houb.push_back({hou[i].first-qian[qian.size()-i].first,hou[i].second})
//			}
//		}
//	}
	return 0;
}