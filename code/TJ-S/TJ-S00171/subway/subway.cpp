#include<iostream>
using namespace std;
int main(){
	int c,n,b,z,i,j;
	int a[501][501],t[501][501],x[100001],y[100001],s[100001],w[500001];
	long long m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++){
		cin>>w[i];
	}
	for(i=1;i<=n;i++){
		cin>>z;
		for(j=1;j<=z;j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		b=x[i];
		s[i]=w[i];
		while(b==y[i]){
			for(int j=x[i];j<=y[i];j++){
				for(int k=1;k<=y[i];k++){
					if(a[j][k]==b){
						s[i]+t[j][k]+w[a[j][k+1]];
						b=a[j][k+1];
					}
				}
			}
		}
		cout<<s[i]<<endl;
	}
	return 0;
} 
