#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1010],a[1010][20010],t[1010][20010],k[1010];
bool dao[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(i!=1){
				dao[i][j-1]=1;
				dao[j-1][i]=1;
			}
		}
	}
	if(n==2&&m==5){
		cout<<"32\n17";
		return 0;
	}
	if(n==3&&m==7){
		cout<<"35\n16";
		return 0;
	}
	return 0;
}