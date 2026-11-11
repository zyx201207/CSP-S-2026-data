#include<bits/stdc++.h>
using namespace std;
int a[100005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]++; 
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
} 
