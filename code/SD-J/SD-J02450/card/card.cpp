#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500010],f[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
