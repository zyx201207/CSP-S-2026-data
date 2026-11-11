#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int ans[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int j=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==j){
			ans[j]=n-i+1;
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
