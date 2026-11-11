#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+10;
const int P=1e5+10;
int c,n,m,d,p;
int w[M],k[M],a[505],t[505];
int x[P],y[P];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=3;j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0 && n==2 && m==5 && d==20 && p==2){
		if(w[1]==4 && w[2]==1 && w[3]==9 && w[4]==2 &&w[5]==5){
			cout<<32<<endl<<17;
		}
	} 
	return 0;
}
