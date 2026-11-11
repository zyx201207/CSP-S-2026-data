#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int c,n,m,d,q;
int w[maxn];
int xr,yr;
int a[10000][505];
int t[10000][505];
int k;

int main(){
 	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
 	for(int i=0;i<m;i++){
 		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>xr>>yr;
	}
	
	
	
	
	
 	return 0;
 } 
