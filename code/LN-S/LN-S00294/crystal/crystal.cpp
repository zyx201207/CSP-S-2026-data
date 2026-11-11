#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=+a[i]/m;
	}
	cout<<ans;
	return 0;
}
