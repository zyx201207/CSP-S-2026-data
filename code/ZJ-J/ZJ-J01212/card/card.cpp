#include <bits/stdc++.h>
using namespace std;
int n,m,a[215215],ans[215215];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(ans[a[i]]==0)ans[a[i]]=n-i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
} 

