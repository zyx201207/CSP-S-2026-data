#include<iostream>
#define ll long long
using namespace std;
ll n, m, a[500010], x, i=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	x=a[2]-a[1];
	for(;double(i)*(i+1)/2*x<=m;i++){}
	if(double(i)*(i-1)/2*x==m) cout<<i;
	else cout<<i-1;
	return 0;
}
