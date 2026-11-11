#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,m;
int x[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>x[i];
	}
	int maxx = -99;
	for(int i = 1;i<=n;i++){
		int cnt = x[i];
		for(int t = 1;t<m;t++){
			cnt&=x[i+t];
		}
		maxx = max(cnt,maxx);
	}
	cout<<maxx;
	return 0;
}
