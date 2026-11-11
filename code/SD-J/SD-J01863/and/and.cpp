#include<bits/stdc++.h>
const int M=1e9+5;
using namespace std;
int n,m,a[M],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[1]&a[2];
	for(int i=3;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

