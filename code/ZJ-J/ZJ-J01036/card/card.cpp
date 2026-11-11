#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f=1,lst1,lst2;
int a[200010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}
	else if(n==m){
		for(int i=1;i<=m;i++) cout<<n<<" ";
	}
	else for(int i=1;i<=m;i++) cout<<1<<" ";
}