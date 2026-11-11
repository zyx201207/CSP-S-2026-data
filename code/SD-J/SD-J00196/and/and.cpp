#include<bits/stdc++.h>
using namespace std;
#define int long long
void fc(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
int a[200010],ans;
signed main(){
	fc();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	cout<<ans<<endl;
	return 0;
}
