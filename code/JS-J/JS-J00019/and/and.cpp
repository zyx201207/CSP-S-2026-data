#include<bits/stdc++.h>
using namespace std;
const int N=2e5+78;
int n,m,a[N],f[N];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=INT_MAX;
	for(int i=1;i<=n;i++){
		x=min(x,a[i]);
	}
	cout<<x;
	return 0;
}
