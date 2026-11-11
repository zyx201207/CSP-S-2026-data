#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,char>> a;
	vector<int> sep{0};
	int size=0;
	for(int i=0;i<n;i++){
		int x;char y;
		cin>>x>>y;
		a.push_back({x,y});
		size+=x;
		sep.push_back(size);
	}
	int l=0,r=a.size()-1,ans=0;
	while(l<r){
		if(a[l].second!=a[r].second){
			ans+=min(a[l].first,a[r].first);
		}
		if(a[l].first>a[r].first){
			a[l].first-=a[r].first;
			a[r].first=0;
			--r;
		}
		else if(a[l].first<a[r].first){
			a[r].first-=a[l].first;
			a[l].first=0;
			++l;
		}
		else{
			a[l].first=a[r].first=0;
			++l;--r;
		}
	}
	cout<<ans<<endl;
	return 0;
}


