#include "bits/stdc++.h"
using namespace std;
int c,n,m,d,q,k,ti;
int a[5],b[25];
struct n{
	int x,y;
}p[5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(q--){
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=2*k;j++){
				cin>>b[j];
			}
		}
		cin>>m>>d;
		ti=a[m]+a[d];
		for(int i=1;i<=2*k;i++){
			if(b[i]==m&&i%2!=0){
				ti+=b[i+1];
			}
			else if(b[i]==d&&i%2!=0){
				ti+=b[i+1];
			}
			if(b[i]==m&&b[i+2]==d)ti+=b[i+3];
			else if(b[i]==m&&b[i+4]==d)ti+=b[i+5];
			else ti+=b[i+3]+b[i+5];
		}
			cout<<ti;
	}
}
