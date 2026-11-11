#include<bits/stdc++.h>
#define AKCSPJ ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;//0pts
int a[500010],ans[300010],fi[300010];
signed main(){
	AKCSPJ;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fi[a[i]]=max(fi[a[i]],i);
	}
	for(int i=1;i<=m;i++){
		cout<<fi[i]<<" ";
	}
	return 0;
}
