#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],ma=-1;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ma=max(a[i],ma);
	}
	cout<<ma;
	return 0;
}
