#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,w[500009];
int e[1009][1009],z[1009][1009],a[1009][1009],t[1009][1009];
void solveBF(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			e[i][j]=1e9,z[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(m<=1009){
		solveBF();
	}
	return 0;
} 
