#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[50000005],ma;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>a[x];
		b[a[x]]++;
	}
	for(int i=1;i<=n;i++){
		ma=max(ma,b[i]);
	}
	cout<<ma;
	return 0;
}
