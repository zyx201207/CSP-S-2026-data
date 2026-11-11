#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[500005];
int d[500005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
