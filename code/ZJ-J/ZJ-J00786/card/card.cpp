#include <bits/stdc++.h>
using namespace std;
typedef long long inte;
// O(n)
inte finds(vector<inte> v, inte n){
	for(int i=0;i<v.size();i++){
		if(v[i]==n){
			return i;
		} 
	}
	return -1;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n, m;
	cin>>n>>m;
	vector<inte> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	vector<inte> desk;
	vector<inte> ans(m+1, 0);
	// O(n^3)
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			inte p = finds(desk, v[j]);
			if(p==-1){
				desk.push_back(v[j]);
			}
			else{
				desk.resize(p+1);
			}
		}
		for(int j=0;j<desk.size();j++){
			ans[desk[j]]++;
		}
		desk.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
// Oh no, this problem is the only one problem that i cant find the true solve. 
// I love you CCF! Please let me get 300 points on other problems! 
// Please give me more points!

