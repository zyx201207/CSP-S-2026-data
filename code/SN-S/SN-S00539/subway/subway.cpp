#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,t[10000];
ll a[1502][1502];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			a[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			a[j+m][v]=w;
		}
	}
	for(int k=m+1;k<=n+m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j&&a[k][i]!=1e9&&a[k][j]!=1e9){
					a[i][j]=a[k][i]+a[k][j];
				}
			}
		}
	}
	while(q--){
		int s,z;
		cin>>s>>z;
		cout<<a[s][z]+t[s]+t[z]<<" ";
	}
	return 0;
}
