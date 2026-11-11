#include<bits/stdc++.h>
using namespace std;
int n,d,q,c;
int k[510],m,t[510][500010],a[510][500010],x[100010],y[100010];
long long w[500010];
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		
	}
	return 0;
} 
