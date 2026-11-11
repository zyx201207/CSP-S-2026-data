#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[300005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]=max(ans[a[i]],i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
