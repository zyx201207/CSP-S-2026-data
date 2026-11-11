#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> v; 
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<m;i++){
		cout<<v[i];
	}
	return 0;
}
