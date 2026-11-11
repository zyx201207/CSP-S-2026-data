#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600005];
int v[600005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i-1;j<=n;j++){
			if(a[j]==i) v[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<v[i]<<" ";
	return 0;
}
