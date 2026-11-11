#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long int n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	for(int i=1;i<=m;i++) ans=int(ans&a[i]);
	cout<<int(ans);
	return 0;
}
