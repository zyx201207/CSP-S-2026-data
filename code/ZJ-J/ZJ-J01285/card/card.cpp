#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int a[10000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans[10000];
	int z[1000];
	for(int i=1;i<=n;i++){
		ans[i]=a[i];
		for(int j=1;j<=n;j++){
			if(ans[j]==1&& ans[i]==m){
				z[i]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<' ';
	}
	return 0;
}
