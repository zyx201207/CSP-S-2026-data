#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>mp;
int n,k;
int rt = 0;
int cnt[100005];
int main(){
	int c,t;
	cin>>c>>t;
	while(n--){
		for(int i = 0;i<=n;i++){
			cnt[i] = 0;
		}
		cin>>n>>k;
		for(int i = 1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		if(k == 2){
			cout<<n/2;
		}
	}
}
