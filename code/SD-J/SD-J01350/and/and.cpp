#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
vector<int> a;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	a.resize(n);
	for(auto &i:a) cin>>i;
	for(int i=30;i>=0;i--){
		int cnt=0,al=a.size();
		vector<int> tmp;
		for(int j=0;j<al;j++) if(a[j]&(1<<i)) cnt++,tmp.push_back(a[j]);
		if(cnt>=m){
			swap(tmp,a);
			ans|=1<<i;
		}
	}
	cout<<ans;
	return 0;
}
