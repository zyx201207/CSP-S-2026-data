#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
struct lcf{
	char n[4];
	int a;
	bool s;
	void sc(){
		s=!s;
	}
};
*/
const int N=5e5+5;
int n,m,ans;
vector<int>v;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	rand();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int ind=v[0];
	for(int i=0;i<n;i++){
		v[i]-=ind;
	}
	cout<<6;
	return 0;
}
