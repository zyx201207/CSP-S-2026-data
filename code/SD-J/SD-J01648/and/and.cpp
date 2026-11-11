#include<bits/stdc++.h>
using namespace std;
int n,m,c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	cout<<c[n-m];
	return 0;
}
