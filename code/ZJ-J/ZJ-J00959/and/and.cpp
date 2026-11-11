#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in ","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100001],ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans/n;
	return 0;
}
