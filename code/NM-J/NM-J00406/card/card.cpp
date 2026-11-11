#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	vector<int> a;
	cin>>n>>m;
	a.push_back(114514);
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	vector<int> ans(m+1,0);
	for(int i=1;i<=n;i++){
		vector<int> pile(a.begin()+i,a.end()),table;
		for(int j:pile){
			auto it=find(table.begin(),table.end(),j);
			if(it!=table.end()){
				table.erase(it,table.end());
			}
				table.push_back(j);
		}
		for(int i=1;i<=m;i++){
			auto it=find(table.begin(),table.end(),i);
			if(it!=table.end())ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}


