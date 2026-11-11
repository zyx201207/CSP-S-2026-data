#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
vector<int> vis[1000005];
int ans[1000005];
int l[1000005],r[1000005];
deque<pair<int,int>> st;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]].push_back(i);
	}
	/*for(int i=1;i<=m;i++){
		for(int it:vis[i]){
			
		}
	}*/
	for(int i=n;i>=1;i--){
		int nl=vis[a[i]].front();
		while(!st.empty()&&st.back().first>i) st.pop_back();
		if(st.front().first>nl) st.push_front({nl,i});
		r[i]=st.back().second;		
	}
	while(!st.empty()) st.pop_back();
	for(int i=1;i<=n;i++){
		int nr=vis[a[i]].back();
		while(!st.empty()&&st.back().second<i) st.pop_back();
		if(st.front().second<nr) st.push_front({i,nr});
		l[i]=st.back().first;
	}
	for(int i=1;i<=n;i++) cout<<l[i]<<' '<<r[i]<<'\n';
}
