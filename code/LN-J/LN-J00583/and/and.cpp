#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int N=2e5+5;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	vector<ll> v;
	for(int i=1;i<=m;i++){
		v.push_back(a[i]);
	}
	ll and_sum=v[0];
	for(auto x:v){
		and_sum&=x;
	}
	cout<<and_sum;
	return 0;
}
