#include<bits/stdc++.h>
using namespace std;
long long n,m,o,l,a[1000001],ans[10001],maxn[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]+1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==i){
				ans[i]=ans[j];
			}
		}
	}
 	for(int i=1;i<=m;i++){
 		cout<<ans[i]<<' ';
	}
	return 0;
}
