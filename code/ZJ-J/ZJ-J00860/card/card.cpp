#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],ans[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i] && i!=1){
			p=0;
		}
		if(a[i-1]<a[i]){
			ans[a[i-1]]=i-1;
		}
	}
	for(int i=1;i<=m-1;i++){
		cout<<ans[i]<<" ";
	}
	cout<<n;
	return 0;
}
