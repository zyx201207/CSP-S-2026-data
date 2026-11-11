#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[100005],ans=1e9,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=min(ans,a[i]);
	}
	cout<<ans;
	return 0;
}