#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,ans=1;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
}
