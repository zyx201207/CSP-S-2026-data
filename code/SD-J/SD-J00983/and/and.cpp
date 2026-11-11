#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
unsigned ans=-1,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=m;++i)ans&=a[i];
	cout<<ans;
	return 0;
}
