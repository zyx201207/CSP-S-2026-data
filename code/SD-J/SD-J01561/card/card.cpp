#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;


signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<int>a;
	int n,m;
	cin>>n>>m;
	set<int>mm;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		mm.insert(x);
	}
	for(auto it:mm){
		cout<<it;
	}
}
//4 2
//3 15 12 12

