#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+10;
int n,m;
int a[N];
unordered_multiset<int> s;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	int ans=0;
	for(int j=29;j>=0;j--){
		unordered_multiset<int> t;
		for(auto &x:s){
			if(x&(1<<j)) t.insert(x);
		}
		if(t.size()>=m) ans|=(1<<j),s=t;
	}
	cout<<ans;
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}
