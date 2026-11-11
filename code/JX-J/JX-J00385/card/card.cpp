#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cout<<i<<' ';
	}
	if(n==m){
		for(int i=1;i<n;i++){
			ans[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		bool f=0;
		int p[500005],z=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<z;k++){
				if(p[k]==a[j]){
					z=k+1;
					f=1;
					break;
				}
			}
			if(!f){
				p[z++]=a[j];
			}else f=0;
		}
		for(int j=0;j<z;j++){
			ans[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
