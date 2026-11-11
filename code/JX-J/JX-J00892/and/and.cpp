#include<bits/stdc++.h>
using namespace std;
int mo[200001][30],maxx,ji;
long long a[200001];
int n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=29;j++){
			mo[i][j]=a[i]%2;
			a[i]/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=29;k>=1;k--){
				ji=ji*2+(mo[i][k]&&mo[j][k]);
			}
			maxx=max(maxx,ji);
		}
	}
	cout<<maxx;
	return 0;
}
