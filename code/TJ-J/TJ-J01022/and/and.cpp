#include<bits/stdc++.h>
using namespace std;

int size_(int a){
	int p = 0;
	while(a > 1){
		a/=2;
		p++;
	}
	return p;
}

int pow_(int a){
	if(a==0) return 0;
	return 1<<a;
}

bool cmp(pair<int,int> &a, pair<int,int> &b){
	if(a.first != b.first) return a.first<b.first;
	return a.second < b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> > v;
	//unordered_set<int> s;
	vector<int> v2;
	for(int i =0;i<n;++i){
		int t; cin>>t;
		//if(!s.empty() && find(s.begin(), s.end(), t) != s.end()){
		//	v2.push_back(t);
		//}
		//else s.insert(t);
		int k = size_(t);
		v.push_back({k, t-pow_(k)});
	}
	
	sort(v.begin(),v.end(),cmp);
	
	
	int ans;
	for(int i=0;i<m;i++){
		while(v.size() > m-i && v[n-2].first != v[n-1].first && v[n-1].second == 0){
			v.pop_back();
		}
		int num = pow_(v.back().first)  + v.back().second;
		if(i == 0){
			ans = num;
			v.pop_back();
			continue;
		}
		ans &= num;
		v.pop_back();
	}
	//sort(v2.begin(), v2.end());
	cout<<ans<<'\n';
	
	return 0;
}
