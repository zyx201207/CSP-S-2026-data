#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
vector<pair<long long,char> >v;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	int l=0,r=n-1;
	int ans=0;
	while(l<r){
		if(v[l].second==v[r].second){
			if(v[l].first==v[r].first){
				l++;
				r--;
			}
			else if(v[l].first>v[r].first){
				v[l].first-=v[r].first;
				r--;
			}
			else{
				v[r].first-=v[l].first;
				l++;
			}
		}
		else{
			ans+=min(v[l].first,v[r].first);
			if(v[l].first==v[r].first){
				l++;
				r--;
			}
			else if(v[l].first>v[r].first){
				v[l].first-=v[r].first;
				r--;
			}
			else{
				v[r].first-=v[l].first;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
