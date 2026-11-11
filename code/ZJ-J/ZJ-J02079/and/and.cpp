#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	cout<<x[n-m+1];
	return 0;
}