#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
map<int,int> mp;
void solve(int x){
	set<int> st;
	map<int,int> mp2;
	for(int i=x;i<=n;i++){
		if(st.count(a[i])){
			for(int j=mp2[a[i]];j<i;j++){
				if(!st.empty()) st.erase(a[j]);
				if(!mp2.empty()) mp2.erase(a[j]);
			}
		}
		st.insert(a[i]);
		mp2[a[i]]=i;
	}
	for(auto i:st){
		mp[i]++;
	}
} 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(auto i:mp){
		cout<<i.second<<' ';
	}
	return 0;
}
