#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500000],cnt[300000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]=i;
	}
	for(int j=1;j<=m;j++){
		cout<<cnt[j];
	}
	return 0;
} 
