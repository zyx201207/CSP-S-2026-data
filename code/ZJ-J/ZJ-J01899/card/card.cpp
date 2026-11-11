#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int pre[300005];
int pre2[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre2[a[i]]=pre[a[i]];
		pre[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
		}
	}
	return 0;
}