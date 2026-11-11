#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long minv=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minv=min(minv,a[i]);
	}
	cout<<minv;
	return 0;
}